#include <iostream>

#include "check_input.h"

using namespace std;

void check_input_int(int& x) {
	cin >> x;
	while (cin.fail() or x < 0 or cin.peek() != '\n' or cin.peek() == ' ') {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "incorrect input! try again ";
		cin >> x;
	}
}

void check_input_double(double& x) {
	cin >> x;
	while (cin.fail() or x < 0 or cin.peek() != '\n' or cin.peek() == ' ') {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "incorrect input! try again ";
		cin >> x;
	}
}

void check_input_bool(bool& x) {
	cin >> x;
	while (cin.fail() or x < 0 or cin.peek() != '\n' || cin.peek() == ' ') {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "incorrect input! try again ";
		cin >> x;
	}
}