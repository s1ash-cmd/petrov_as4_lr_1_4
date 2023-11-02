#pragma once
#include <string>

using namespace std;

class station {
public:
	string sname;
	int number_of_workshops;
	int workshops_in_work;
	double eff;
};

station station_input();
void station_output(const station& new_station);
void station_change_status(station& new_station);
void write_station_file(station new_station, pipe new_pipe);
void read_station_file(station& new_station);