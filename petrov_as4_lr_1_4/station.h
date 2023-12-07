#pragma once
#include <string>

using namespace std;

class station {
	int id;
public:
	string sname = "";
	int number_of_workshops = 0;
	int workshops_in_work = 0;
	double eff = 0.0;

	static int ID;
	station();

	friend istream& operator >> (istream& in, station& new_station);
	friend ostream& operator << (ostream& out, station& new_station);
	friend ofstream& operator << (ofstream& fout, station& new_station);
	friend ifstream& operator >> (ifstream& fin, station& new_station);

	int getid() { return id; };
};