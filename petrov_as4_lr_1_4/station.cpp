#include "station.h"
#include "header.h"

#include <unordered_map>
#include <cmath>
#include <fstream>

using namespace std;

int station::ID = 1;

station::station()
{
	id = ID++;
}

istream& operator>>(istream& in, station& new_station){
	cout << "enter station name ";
	cin.ignore();
	getline(cin, new_station.sname);

	cout << "enter the number of workshops: ";
	new_station.number_of_workshops = check_input(0, 1000);

	cout << "enter the number of workshops in work: ";
	new_station.workshops_in_work = check_input(0, 1000);

	while (new_station.number_of_workshops < new_station.workshops_in_work) {
		cout << "the number of working workshops cant be more than the total number of workshops" << endl << "enter again ";
		new_station.workshops_in_work = check_input(0, 10000);
	}

	new_station.eff = round(double(new_station.workshops_in_work) / double(new_station.number_of_workshops) * 100);
	cout << "eff of the station: " << new_station.eff << "%" << endl;
	return in;
}

ostream& operator<<(ostream& out, station& new_station) {
	out << "\nstation id is: " << new_station.id << endl;
	out << "station name is: " << new_station.sname << endl;
	out << "total number of workshops: " << new_station.number_of_workshops << endl;
	out << "number of workshops in work: " << new_station.workshops_in_work << endl;
	out << "eff of the station: " << new_station.eff << "%" << endl;
	out << "--------------------------------" << endl;
	return out;
}

ofstream& operator<<(ofstream& fout, station& new_station) {
	fout << new_station.sname << endl << new_station.number_of_workshops << endl << new_station.workshops_in_work << endl << new_station.eff << endl;
	return fout;
}
ifstream& operator>>(ifstream& fin, station& new_station) {
	fin.ignore();
	getline(fin, new_station.sname);
	fin >> new_station.number_of_workshops;
	fin >> new_station.workshops_in_work;
	fin >> new_station.eff;
	return fin;
}
