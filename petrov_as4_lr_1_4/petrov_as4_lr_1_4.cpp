#include <iostream>
#include <string>
#include <fstream>

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
	double eff;
};

pipe pipe_input() {
	pipe new_pipe;

	cout << "enter pipe name: ";
	cin >> new_pipe.pname;

	cout << "enter pipe length: ";
	cin >> new_pipe.length;

	cout << "enter pipe diameter: ";
	cin >> new_pipe.diameter;

	cout << "is the pipe under repair? (1 - yes, 0 - no): ";
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

	while (new_station.number_of_workshops < new_station.workshops_in_work) {
		cout << "the number of working workshops cant be more than the total number of workshops" << endl << "enter again ";
		cin >> new_station.workshops_in_work;
	}

	cout << "enter eff (0.0 - 1.0) ";
	cin >> new_station.eff;

	return new_station;
}

void pipe_output(const pipe& new_pipe) {
	if (new_pipe.pname.empty()) {
		cout << "no pipe found";
	}

	else {
		cout << "pipe name is " << new_pipe.pname << endl;
		cout << "pipe length is " << new_pipe.length << endl;
		cout << "pipe diameter is " << new_pipe.diameter << endl;
		cout << "pipe under repair? " << new_pipe.repair << endl;
	}
};

void station_output(const station& new_station) {
	if (new_station.sname.empty()) {
		cout << "no station found";
	}

	else {
		cout << "station name is " << new_station.sname << endl;
		cout << "total number of workshops: " << new_station.number_of_workshops << endl;
		cout << "number of workshops in work: " << new_station.workshops_in_work << endl;
		cout << "eff of the station: " << new_station.eff << endl;
	}
};

pipe pipe_change_status(pipe new_pipe) {
	new_pipe.repair = !new_pipe.repair;
	cout << "pipe status has been changed" << endl;
	cout << "new pipe repair status is: " << new_pipe.repair << endl;
	return new_pipe;
}

station station_change_status(station new_station) {
	cout << "the number of workshops: " << new_station.number_of_workshops << endl;
	cout << "the number of working workshops: " << new_station.workshops_in_work << endl;
	cout << "enter new number of working workshops: ";
	cin >> new_station.workshops_in_work;

	while (new_station.number_of_workshops < new_station.workshops_in_work) {
		cout << "the number of working workshops cant be more than the total number of workshops" << endl << "enter again ";
		cin >> new_station.workshops_in_work;
	}
	return new_station;
}

void write_pipe_file(pipe new_pipe) {
	ofstream file_out;
	file_out.open("file.txt", ofstream::app);
	if (file_out.is_open()) {
		if (!new_pipe.pname.empty()) {
			file_out << "pipe: " << endl;
			file_out << new_pipe.pname << endl << new_pipe.length << endl
				<< new_pipe.diameter << endl << new_pipe.repair << endl;
		}
		else {
			cout << "no pipe found" << endl;
		}
		file_out.close();
	}
	else {
		cout << "couldnt open file" << endl;
	}
}

void write_station_file(station new_station) {
	ofstream file_out;
	file_out.open("file.txt", ofstream::app);
	if (file_out.is_open()) {
		if (!new_station.sname.empty()) {
			file_out << "station: " << endl;
			file_out << new_station.sname << endl << new_station.number_of_workshops
				<< endl << new_station.workshops_in_work << endl << new_station.eff << endl;
		}
		else {
			cout << "no station found" << endl;
		}
		file_out.close();
	}
	else {
		cout << "couldnt open file" << endl;
	}
}

int main() {
	int choice;
	pipe new_pipe;
	station new_station;

	for (;;) {
		cout << "\n_____menu_____" << endl;
		cout << "1) add new pipe" << endl;
		cout << "2) add new station" << endl;
		cout << "3) see all objets" << endl;
		cout << "4) edit pipe status" << endl;
		cout << "5) edit workstations in work" << endl;
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
			cout << "\npipe:" << endl;
			pipe_output(new_pipe);

			cout << "\nstaion:" << endl;
			station_output(new_station);
			break;
		}
		case 4: {
			new_pipe = pipe_change_status(new_pipe);
			break;
		}
		case 5: {
			new_station = station_change_status(new_station);
			break;
		}
		case 6: {
			write_pipe_file(new_pipe);
			write_station_file(new_station);

		}
		}
	}
}