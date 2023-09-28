﻿#include <iostream>
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

pipe pipe_input() {
	pipe new_pipe;

	cout << "enter pipe name: ";
	cin.ignore();
	getline(cin, new_pipe.pname);

	cout << "enter pipe length: ";
	check_input_double(new_pipe.length);

	cout << "enter pipe diameter: ";
	check_input_double(new_pipe.diameter);

	cout << "is the pipe under repair? (1 - yes, 0 - no): ";
	check_input_bool(new_pipe.repair);

	return new_pipe;
}

station station_input() {
	station new_station;

	cout << "enter station name ";
	cin.ignore();
	getline(cin, new_station.sname);

	cout << "enter the number of workshops ";
	check_input_int(new_station.number_of_workshops);

	cout << "enter the number of workshops in work ";
	check_input_int(new_station.workshops_in_work);

	while (new_station.number_of_workshops < new_station.workshops_in_work) {
		cout << "the number of working workshops cant be more than the total number of workshops" << endl << "enter again ";
		check_input_int(new_station.workshops_in_work);
	}

	cout << "enter eff (0.0 - 1.0) ";
	check_input_double(new_station.eff);

	while (new_station.eff > 1) {
		cout << "incorrect input! try again ";
		check_input_double(new_station.eff);
	}
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

pipe pipe_change_status(pipe new_pipe) { //????????????????????????????????????
	new_pipe.repair = !new_pipe.repair;
	cout << "pipe status has been changed" << endl;
	cout << "new pipe repair status is: " << new_pipe.repair << endl;
	return new_pipe;
}

station station_change_status(station new_station) {//????????????????????????????????????????
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

void write_pipe_file(pipe new_pipe) { //!!!
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

void write_station_file(station new_station) {//!!
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

void read_pipe_file(pipe& new_pipe) {
	ifstream file_in;
	string pstr;
	file_in.open("file.txt");
	if (file_in.is_open()) {
		while (getline(file_in, pstr)) {
			if (pstr == "pipe: ") {	//!!
				cout << pstr << endl;
				file_in >> new_pipe.pname;
				file_in >> new_pipe.length;
				file_in >> new_pipe.diameter;
				file_in >> new_pipe.repair;
				pipe_output(new_pipe);
			}
		}
		file_in.close();
	}
	else {
		cout << "file couldnt be open " << endl;
	}
}

void read_station_file(station& new_station) {
	ifstream file_in;
	string sstr;
	file_in.open("file.txt");
	if (file_in.is_open()) {
		while (getline(file_in, sstr)) {
			if (sstr == "station: ") {
				cout << sstr << endl;
				file_in >> new_station.sname;
				file_in >> new_station.number_of_workshops;
				file_in >> new_station.workshops_in_work;
				file_in >> new_station.eff;
				station_output(new_station);
			}
		}
		file_in.close();
	}
	else {
		cout << "file couldnt be open " << endl;
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

		check_input_int(choice);

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
			if (!new_pipe.pname.empty()) {
				new_pipe = pipe_change_status(new_pipe);
			}
			else {
				cout << "no pipe found" << endl;
			}
			break;
		}
		case 5: {
			if (!new_station.sname.empty()) {
				new_station = station_change_status(new_station);
			}
			else {
				cout << "no station found" << endl;
			}
			break;
		}
		case 6: {
			write_pipe_file(new_pipe);
			write_station_file(new_station);
			break;
		}
		case 7: {
			read_pipe_file(new_pipe);
			read_station_file(new_station);
			break;
		}
		case 0: {
			return 0;
		}
		default:
			cout << "wrong choice. enter again " << endl;
			break;
		}
	}
}