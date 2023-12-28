#include <iostream>
#include <fstream>
#include <unordered_map>
#include <chrono>
#include <format>

#include "pipe.h"
#include "station.h"
#include "header.h"
#include "gts.h"

using namespace std;
using namespace chrono;

int main() {
	redirected_output cerr_out(cerr);
	string time = std::format("{:%d_%m_%Y %H_%M_%OS}", system_clock::now());
	ofstream logfile("log_" + time + ".txt");
	if (logfile) {
		cerr_out.redirect(logfile);
	}

	unordered_map <int, pipe> pipes;
	unordered_map <int, station> stations;
	vector <vector <int> > matrica;

	gts sistema;

	for (;;) {
		sistema.printmenu();
		int choice = check_input(0, 14);

		switch (choice) {
		case 1: {
			pipe new_pipe;
			cin >> new_pipe;
			pipes.insert({ new_pipe.getid(),new_pipe });
			break;
		}
		case 2: {
			station new_station;
			cin >> new_station;
			stations.insert({ new_station.getid(),new_station });
			break;
		}
		case 3: {
			sistema.pipe_output(pipes);
			sistema.station_output(stations);
			sistema.viewgts(matrica);
			break;
		}
		case 4: {
			sistema.pipe_edit(pipes);
			break;
		}
		case 5: {
			sistema.station_edit(stations);
			break;
		}
		case 6: {
			sistema.pipe_delete(pipes);
			break;
		}
		case 7: {
			sistema.station_delete(stations);
			break;
		}
		case 8: {
			sistema.combine(stations, pipes, matrica);
			break;
		}
		case 9: {
			sistema.deleteconnection(pipes, stations, matrica);
			break;
		}
		case 10: {
			sistema.topolog(matrica);;
			break;
		}
		/*case 11: {
			sistema.shortestdistance(pipes, stations, matrica);
			break;
		}
		case 12: {
			sistema.maxflow(pipes, stations, matrica);
			break;
		}*/
		case 13: {
			sistema.data_write(pipes, stations);
			break;
		}
		case 14: {
			sistema.data_read(pipes, stations);
			break;
		}
		case 0: {
			return 0;
		}
		}
	}
	return 0;
}