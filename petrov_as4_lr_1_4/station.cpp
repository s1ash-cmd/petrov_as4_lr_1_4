#include <iostream>
#include <fstream>

#include "pipe.h"
#include "station.h"
#include "check_input.h"

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

void station_change_status(station& new_station) {
	cout << "the number of workshops: " << new_station.number_of_workshops << endl;
	cout << "the number of working workshops: " << new_station.workshops_in_work << endl;
	cout << "enter new number of working workshops: ";
	check_input_int(new_station.workshops_in_work);

	while (new_station.number_of_workshops < new_station.workshops_in_work) {
		cout << "the number of working workshops cant be more than the total number of workshops" << endl << "enter again ";
		check_input_int(new_station.workshops_in_work);
	}
}

void write_station_file(station new_station, pipe new_pipe) {
	ofstream file_out;

	if (new_pipe.pname.empty()) {
		file_out.open("file.txt");
	}
	else {
		file_out.open("file.txt", ofstream::app);
	}

	if (!new_station.sname.empty()) {
		if (file_out.is_open()) {
			file_out << "station: " << endl;
			file_out << new_station.sname << endl << new_station.number_of_workshops
				<< endl << new_station.workshops_in_work << endl << new_station.eff << endl;
		}
		else {
			cout << "couldnt open file" << endl;
		}
		file_out.close();
	}
	else {
		cout << "no station found" << endl;
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