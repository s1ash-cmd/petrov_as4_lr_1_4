#include <iostream>
#include <string>

using namespace std;

struct pipe {
	string pname;
	double length;
	double diameter;
	bool repair;
};

struct station {
	string sname;
	int number_of_workshops;
	int workshops_in_work;
	double efficency;
};

pipe pipe_input() {
	pipe new_pipe;

	cout << "Enter pipe name: ";
	cin >> new_pipe.pname;

	cout << "Enter pipe length: ";
	cin >> new_pipe.length;

	cout << "Enter pipe diameter: ";
	cin >> new_pipe.diameter;

	cout << "Is the pipe under repair? (1 - yes, 0 - no): ";
	cin >> new_pipe.repair;

	return new_pipe;
}

station station_input() {
	station new_station;

	cout << "enter station name ";
	cin >> new_station.sname;

	cout << "enter the number of workshops ";
	cin >> new_station.number_of_workshops;

	cout << "enter the number of workshops in work ";
	cin >> new_station.workshops_in_work;

	cout << "enter efficency ";
	cin >> new_station.efficency;

	return new_station;
}

void pipe_output(pipe new_pipe) {
	cout << "pipe name is " << new_pipe.pname << endl;
	cout << "pipe length is " << new_pipe.length << endl;
	cout << "pipe diameter is " << new_pipe.diameter << endl;
	cout << "pipe under repair? " << new_pipe.repair << endl;
};

void station_output(station new_station) {
	cout << "station name is " << new_station.sname << endl;
	cout << "total number of workshops: " << new_station.number_of_workshops << endl;
	cout << "number of workshops in work: " << new_station.workshops_in_work << endl;
	cout << "efficency of the station: " << new_station.efficency << endl;
};

int main() {
	int choice;
	pipe new_pipe;
	station new_station;

	for (;;) {
		cout << "\n_____menu_____" << endl;
		cout << "1) add new pipe" << endl;
		cout << "2) add new station" << endl;
		cout << "3) see all objets" << endl;
		cout << "4) edit pipe" << endl;
		cout << "5) edit station" << endl;
		cout << "6) save to file" << endl;
		cout << "7) load from file" << endl;
		cout << "0) exit" << endl;
		cout << "===============================" << endl;
		cout << "enter a number ";
		cin >> choice;

		switch (choice) {
		case 1: {
			new_pipe = pipe_input();
			break;
		}
		case 2: {
			new_station = station_input();
			break;
		}

		case 3: {
			cout << "\nPipe:" << endl;
			pipe_output(new_pipe);

			cout << "\nStaion:" << endl;
			station_output(new_station);
			break;
		}
		case 4: {

		}
		}
	}
}