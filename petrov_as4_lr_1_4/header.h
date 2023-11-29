#pragma once
#include <iostream>

using namespace std;

template <typename T>
void check_input(T& x) {
	while (true) {
		if (cin >> x && x >= 0) {
			char nextChar = cin.get();
			if (nextChar == '\n' || nextChar == ' ' || nextChar == '\t') {
				break;
			}
		}
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "incorrect input! try again ";
	}
}