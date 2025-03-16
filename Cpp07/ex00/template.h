#ifndef TEMPLATE_H
	#define TEMPLATE_H

template <typename T>
T max(T a, T b)
{
	return(a > b) ? a : b;
}

template <typename T>
T min (T a, T b)
{
	return (a < b) ? a : b;
}

template <typename T>
void swap(T a, T b)
{
	T c;
	c = a;
	a = b;
	a = c;
	return ;
}
#endif