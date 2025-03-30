	#ifndef BITCOINEXCHANGE_HPP
		#define BITCOINEXCHANGE_HPP

	#include <iostream>  
	#include <map>
	#include <fstream>
	#include <string>
	#include <cstdlib>
	#include <sstream>

	template <typename T>
	T stringToValue(const std::string& str) {
		std::stringstream ss(str);
		T result;
		ss >> result;
		if (ss.fail() || !ss.eof()) {
			return T();
		}
		return result;
	}



	typedef struct s_date
	{
		int year;
		int month;
		int day;
		std::string error;

		bool operator<(const s_date &date) const;
		bool operator>(const s_date &date) const;
		bool operator==(const s_date &date) const;
		bool operator<=(const s_date &date) const;
		bool operator>=(const s_date &date) const;
	} 			t_date;

	class BitcoinExchange
	{
		private:
			std::map<t_date, double> _data;
			std::map<t_date, double> _btc_data;

		public:
			BitcoinExchange();
			BitcoinExchange(const BitcoinExchange &obj);
			BitcoinExchange &operator=(const BitcoinExchange &old);
			~BitcoinExchange();
			void stockDataFromDatabase();
			void readInputFile(std::string filename);
			void compareData();

	};

	#endif