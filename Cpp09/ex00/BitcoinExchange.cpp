#include "BitcoinExchange.hpp"


//Constructor and Destructor For BitcoinExchange
BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &old)
{
	if (this != &old)
	{
		this->_data = old._data;
	}
	return (*this);
}


BitcoinExchange::~BitcoinExchange()
{

}

//Operator for Date structure
bool t_date::operator<(const t_date &date) const
{
	if (year < date.year)
		return (true);
	if (year == date.year && month < date.month)
		return (true);
	if (year == date.year && month == date.month && day < date.day)
		return (true);
	return (false);
}

bool t_date::operator>(const t_date &date) const
{
	if (year > date.year)
		return (true);
	if (year == date.year && month > date.month)
		return (true);
	if (year == date.year && month == date.month && day > date.day)
		return (true);
	return (false);
}

bool t_date::operator==(const t_date &date) const
{
	return (year == date.year && month == date.month && day == date.day);
}

bool t_date::operator<=(const t_date &date) const
{
	if (*this < date || *this == date)
		return (true);
	return (false);
}

bool t_date::operator>=(const t_date &date) const
{
	if (*this > date || *this == date)
		return (true);
	return (false);
}


//Utility functions

/**
 * @brief Check if a string is a number
 * @param str : the string to check
 * @return 0 if the string is a number, 1 otherwise
 */
int str_is_number(std::string str)
{
	if (str.empty())
		return (1);
	size_t len = str.length();
	int	space = 0;
	for (size_t i = 0; i < len; i++)
	{	
		while(space == 0 && str[i] == ' ')
			i++;
		space++;
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			return (1);
	}
	return (0);
}

/**
 * @brief Check if a date is valid in the right
 * @param year : the year to check
 * @param month : the month to check
 * @param day : the day to check
 * @return 0 if the date is valid, 1 otherwise
 * @note The date must be in the format YYYY-MM-DD
 * 
 */
int date_is_wrong(int year, int month, int day, t_date *date)
{
	if (year < 2009)
	{
		date->error = "Error: Year must be greater than 2009";
		return (1);
	}
	if (month < 1 || month > 12)
	{
		date->error = "Error: Month must be between 1 and 12";
		return (1);
	}
	if (day < 1 || day > 31)
	{
		date->error = "Error: Day can't exceed 31 and can't be less than 1";
		return (1);
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		date->error = "Error: April, June, September and November have 30 days";
		return (1);
	}
	if (month == 2 && day > 29)
	{
		date->error = "Error: February has 28 days or 29 days in leap years";
		return (1);
	}
	if ((month == 2 && day == 29 && year % 4 != 0) || (year % 100 == 0 && year % 400 != 0))
	{
		date->error = "Error: February has 28 days or 29 days in leap years";
		return (1);
	}
	return (0);
}



/**
 * @brief Check if a string is a date in format YYYY-MM-DD
 * @param str : the string to check
 * @return NULL if the string is not a date, a t_date structure otherwise
 */
t_date str_is_date(std::string str)
{
	t_date date;
	date.error = "No error";
	if (str.length() > 11 || str.length() < 10)
	{
		date.error = "Error: Date must be in format YYYY-MM-DD";
		return (date);
	}
	if (str[4] != '-' || str[7] != '-')
	{
		date.error = "Error: Date must be in format YYYY-MM-DD";
		return (date);
	}
	for (int i = 0; i < 10; i++)
	{
		if (!isdigit(str[i]) && i != 4 && i != 7)
		{
			date.error = "Error: Date must be in format YYYY-MM-DD";
			return (date);
		}
	}
	int year = stringToValue<int>(str.substr(0, 4));
	if (year < 2009)
	{
		date.error = "Error: Year must be greater than 2009";
		return (date);
	}
	int month = stringToValue<int>(str.substr(5, 2));
	int day = stringToValue<int>(str.substr(8, 2));
	date.year = year;
	date.month = month;
	date.day = day;
	if (date_is_wrong(year, month, day, &date))
		return (date);
	return (date);
}


// Mains functions

/**
 * @brief Compare data from the input file and the database
 * 		Print the result in the format YYYY-MM-DD => value = value
 * 		If the date is not in the database, use the last date in the database
 * 		If the date is not in the input file, print an error message
 * @param void
 * @return void
 */
void BitcoinExchange::compareData()
{
	std::map<t_date, double>::iterator it;
	for (it = this->_data.begin(); it != this->_data.end(); ++it)
	{
		if (it->first.error != "No error")
		{
			std::cout << it->first.error << std::endl;
			continue;
		}
		std::map<t_date, double>::iterator btc_it = this->_btc_data.find(it->first);
		if (btc_it != this->_btc_data.end())
		{
			std::cout << it->first.year << "-" << it->first.month << "-" << it->first.day << " => " << it->second
				<< " = " << btc_it->second * it->second << std::endl;
		}
		else
		{
			std::map<t_date, double>::iterator second_it;
			if (this->_btc_data.empty())
			{
				std::cout << it->first.year << "-" << it->first.month << "-" << it->first.day << " => " << it->second
					<< " = " << 0 << std::endl;
				continue;
			}
			for (second_it = this->_btc_data.begin(); second_it != this->_btc_data.end(); ++second_it)
			{
				if (it->first <= second_it->first)
				{
					if (second_it != this->_btc_data.begin())
						--second_it;
					break;
				}
			}
			if (second_it == this->_btc_data.end())
				second_it = --this->_btc_data.end(); // dernier élément
			std::cout << it->first.year << "-" << it->first.month << "-" << it->first.day << " => " << it->second
				<< " = " << second_it->second * it->second << std::endl;
		}
	}
}

/**
 * @brief Stock data from database data.csv in a map
 * @throws if the file cannot be opened
 * @throws the key or value is empty
 * @throws the key is not a date in format YYYY-MM-DD
 * @throws the value is not a number
 * @param void
 * @return void
 */
void BitcoinExchange::stockDataFromDatabase()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		throw std::invalid_argument("Error: Database: File does not exist or cannot be opened.");
	}
	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw std::invalid_argument("Error: Database: first line must be 'date,exchange_rate'.");
	while (std::getline(file, line))
	{
		if (line.empty())
			throw std::runtime_error("Error: Database: line cannot be empty.");	
		std::string key = line.substr(0, line.find(","));
		std::string value = line.substr(line.find(",") + 1);
		if (key.empty() || value.empty())
			throw std::runtime_error("Error: Database: key or value cannot be empty.");
		int all_numbers = str_is_number(value);
		if (all_numbers)
			throw std::runtime_error("Error: Database: value must be a positiv number.");
		t_date date = str_is_date(key);
		double val = 0;
		if (!all_numbers)
			val = stringToValue<double>(value);
		if (date.error != "No error")
			throw std::runtime_error("Error: Database: " + date.error);
		if (val < 0)
			throw std::runtime_error("Error: Database: value cannot be negative.");
		this->_btc_data[date] = val;
	}
	if (this->_btc_data.empty())
		throw std::runtime_error("Error: Database: no data found.");
	file.close();
}


/**
 * @brief 	Read data from a file and store it in a map
 * 			Parse file line by line and store the key value pair in a map
 * 			Keys are dates in format YYYY-MM-DD
 * 			Values are doubles between 0 and 1000
 * @throw 	 if the file cannot be opened
 * @throws		the key or value is empty
 * @throw		the key is not a date in format YYYY-MM-DD
 * @throws		the value is not a number
 * @throws		the value is not between 0 and 1000
 * 
 * @param filename : the name of the file to read
 * @return void
 */
void BitcoinExchange::readInputFile(std::string filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::invalid_argument("Error : File does not exist or cannot be opened.");
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
		throw std::invalid_argument("Error : First line must be 'date | value'.");
	while (std::getline(file, line))
	{
		std::string error;
		if (line.empty())
			error = "Error: Line cannot be empty.";	
		size_t sep_pos = line.find("|");
		if (sep_pos == std::string::npos) {
			t_date date;
			date.error = "Error: Line missing separator '|' -> [" + line + "]";
			size_t find_pos = this->_data.size();
			date.year = find_pos;
			date.month = find_pos;
			date.day = find_pos;
			this->_data[date] = 0;
			continue;
		}
		
		std::string key =  line.substr(0, sep_pos);
		std::string value = line.substr(sep_pos + 1);
		if (key.empty() || value.empty())
			error = "Error: Key or value cannot be empty.";
		int all_numbers = str_is_number(value);
		if (all_numbers || value[0] != ' ')
		{
			error = "Error: Value must be a positive number preceed by a ' '.";
		}
		if (key[10] != ' ')
			error = "Error: Key must be a date in format YYYY-MM-DD followed by space.";
		t_date date = str_is_date(key);
		double val = 0;
		if (!all_numbers)
		{
			val = stringToValue<double>(value);
			if (val < 0 || val > 1000)
				error = "Error: Value can only be between 0 and 1 000.";
		}
		if (date.error != "No error")
			error = date.error;
		if (error.size() > 0)
		{
			date.error = error + " -> [" + key + " | " + value + "]";
			size_t find_pos = this->_data.size();
			if (find_pos <= 0)
				find_pos = 0;
			date.year = find_pos;
			date.month = find_pos;
			date.day = find_pos;
		}
		this->_data[date] = val;
	}
	file.close();
	if (this->_data.empty())
		throw std::runtime_error("Error: No data found in file.");
	stockDataFromDatabase();
	compareData();
}
