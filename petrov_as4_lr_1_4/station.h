#pragma once
#include <string>

using namespace std;

class station {
public:
	int id;
	string sname;
	int number_of_workshops;
	int workshops_in_work;
	double eff;
};

void station_input(station& new_station, int id);
void station_delete(unordered_map<int, station>& stations, int id);
void station_edit(unordered_map<int, station>& stations, int id);
void station_output(const unordered_map<int, station>& stations);
void write_station_file(station new_station, pipe new_pipe);
//void read_station_file(station& new_station);