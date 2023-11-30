#include <iostream>
#include <fstream>
#include <unordered_map>

#include "pipe.h"
#include "station.h"
#include "header.h"

void station_input(station& new_station, int id) {
	new_station.id = id;

	cout << "enter station name ";
	cin.ignore();
	getline(cin, new_station.sname);

	cout << "enter the number of workshops ";
	new_station.number_of_workshops = check_input(0, 10000);

	cout << "enter the number of workshops in work ";
	new_station.workshops_in_work = check_input(0, 10000);

	while (new_station.number_of_workshops < new_station.workshops_in_work) {
		cout << "the number of working workshops cant be more than the total number of workshops" << endl << "enter again ";
		new_station.workshops_in_work = check_input(0, 10000);
	}

	double a = new_station.workshops_in_work;

	new_station.eff =  a / new_station.number_of_workshops;

}

void station_delete(unordered_map<int, station>& stations, int id) {
	auto it = stations.find(id);
	if (it != stations.end()) {
		stations.erase(it);
		cout << "station with id " << id << "has been deleted" << endl;
	}
	else {
		cout << "no station found with that id " << endl;
	}
}

void station_edit(unordered_map<int, station>& stations, int id) {
	auto it = stations.find(id);
	if (it != stations.end()) {
		station& edited_station = it->second;

		cout << "Enter new station name: ";
		cin.ignore();
		getline(cin, edited_station.sname);

		cout << "Enter new total number of workshops: ";
		edited_station.number_of_workshops = check_input(0, 10000);

		cout << "Enter new number of workshops in work: ";
		edited_station.workshops_in_work = check_input(0, 10000);

		while (edited_station.number_of_workshops < edited_station.workshops_in_work) {
			cout << "The number of working workshops can't be more than the total number of workshops. Enter again: ";
			edited_station.workshops_in_work = check_input(0, 10000);
		}

		cout << "Station with id " << id << " edited successfully." << endl;
	}
	else {
		cout << "Station with id " << id << " not found." << endl;
	}
}

void station_output(const unordered_map<int, station>& stations) {
	if (stations.empty()) {
		cout << "no stations found" << endl;
	}

	else {
		for (const auto& pair : stations) {
			const station& new_station = pair.second;
			cout << "station id is " << new_station.id << endl;
			cout << "station name is " << new_station.sname << endl;
			cout << "total number of workshops: " << new_station.number_of_workshops << endl;
			cout << "number of workshops in work: " << new_station.workshops_in_work << endl;
			cout << "eff of the station: " << new_station.eff << endl;
		}
	}
};

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

//void read_station_file(station& new_station) {
//	ifstream file_in;
//	string sstr;
//	file_in.open("file.txt");
//	if (file_in.is_open()) {
//		while (getline(file_in, sstr)) {
//			if (sstr == "station: ") {
//				cout << sstr << endl;
//				file_in >> new_station.sname;
//				file_in >> new_station.number_of_workshops;
//				file_in >> new_station.workshops_in_work;
//				file_in >> new_station.eff;
//				station_output(new_station);
//			}
//		}
//		file_in.close();
//	}
//	else {
//		cout << "file couldnt be open " << endl;
//	}
//}
