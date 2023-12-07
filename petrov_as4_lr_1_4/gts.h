#pragma once
#include "pipe.h"
#include "station.h"

#include <unordered_map>

class gts {
public:
	static void printmenu();

	static void pipe_output(unordered_map<int, pipe> pipes);
	static vector <int> pipe_select(unordered_map<int, pipe> pipes);
	static void pipe_edit(unordered_map<int, pipe>& pipes);
	static void pipe_delete(unordered_map<int, pipe>& pipes);

	static void station_output(unordered_map<int, station> stations);
	static vector<int> station_select(unordered_map<int, station> stations);
	static void station_edit(unordered_map<int, station>& stations);
	static void station_delete(unordered_map<int, station>& stations);

	static void data_write(unordered_map <int, pipe> pipes, unordered_map <int, station> stations);
	static void data_read(unordered_map <int, pipe>& pipes, unordered_map <int, station>& stations);
};