#include <iostream>
#include <string>

using namespace std;

struct pipe {
	string name;
	double length;
	double diameter;
	bool repair;

	void pipe_input() {
		cout << "enter pipe name ";
		cin >> name;

		cout << "enter pipe lenght ";
		cin >> length;

		cout << "enter pipe diametr ";
		cin >> diameter;

		cout << "is the pipe under repair? ";
		cin >> repair;
	}

	void pipe_output() {
		cout << "pipe name is " << name << endl;
		cout << "pipe length is " << length << endl;
		cout << "pipe diameter is " << diameter << endl;
		cout << "pipe under repair? " << repair << endl;
	};
};

struct station {
	string name;
	int number_of_workshops;
	int workshops_in_work;
	double efficency;

	void station_input() {
		cout << "enter station name ";
		cin >> name;

		cout << "enter the number of workshops ";
		cin >> number_of_workshops;

		cout << "enter the number of workshops in work ";
		cin >> workshops_in_work;

		cout << "enter efficency ";
		cin >> efficency;
	}

	void station_output() {
		cout << "station name is " << name << endl;
		cout << "total number of workshops: " << number_of_workshops << endl;
		cout << "number of workshops in work: " << workshops_in_work << endl;
		cout << "efficency of the station" << efficency << endl;
	};
};

int main() {
	int choice;

	cout << "1) add new pipe" << endl;
	cout << "2) add new station" << endl;
	cout << "3) see all objets" << endl;
	cout << "4) edit pipes" << endl;
	cout << "5) edit station" << endl;
	cout << "6) save to file" << endl;
	cout << "7) load from file" << endl;
	cout << "0) exit" << endl;
	cout << "\nenter a number ";
	cin >> choice;

	switch (choice) {
	case 1: {
		pipe new_pipe;
		new_pipe.pipe_input();
		break;
	}
	case 2: {
		station new_station;
		new_station.station_input();
		break;
	}
	}
}