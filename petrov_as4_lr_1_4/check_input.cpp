#include <iostream>

#include "check_input.h"

using namespace std;

//template <typename T>
//void check_input(T& x) {
//    while (true) {
//        if (cin >> x && x >= 0) {
//            char nextChar = cin.get();
//            if (nextChar == '\n' || nextChar == ' ' || nextChar == '\t') {
//                break; 
//            }
//        }
//        cin.clear();
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        cout << "Incorrect input! Try again: ";
//    }
//}


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