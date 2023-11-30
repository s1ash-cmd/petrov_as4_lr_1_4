#pragma once
#include <iostream>

using namespace std;

template <typename T>
T check_input(T min, T max)
{
	T x;
	while ((cin >> x).fail() || (cin).peek() != '\n' || x < min || x > max)
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "\nenter the correct data (" << min << " - " << max << ") ";
	}
	return x;
}