#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

#include "header.h"
#include "pipe.h"
#include "station.h"

using namespace std;

int main() {
	int choice;
	unordered_map <int, pipe> pipes;
	unordered_map <int, station> stations;

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

		check_input(choice);

		switch (choice) {
		case 1: {
			pipe new_pipe;
			pipe_input(new_pipe);
			pipes[pipes.size() + 1] = new_pipe;
			break;
		}
		case 2: {
			station new_station;
			station_input(new_station);
			stations[stations.size() + 1] = new_station;
			break;
		}
		case 3: {
			for (auto& new_pipe : pipes) {
				cout << "\npipe:" << endl;
				pipe_output(new_pipe.second);
			}


			for (auto& new_station : stations) {
				cout << "\nstaion:" << endl;
				station_output(new_station.second);
			}
			break;
		}
		/*case 4: {
			if (!new_pipe.pname.empty()) {
				pipe_change_status(new_pipe);
			}
			else {
				cout << "no pipe found" << endl;
			}
			break;
		}
		case 5: {
			if (!new_station.sname.empty()) {
				station_change_status(new_station);
			}
			else {
				cout << "no station found" << endl;
			}
			break;
		}
		case 6: {
			write_pipe_file(new_pipe);
			write_station_file(new_station, new_pipe);
			break;
		}
		case 7: {
			read_pipe_file(new_pipe);
			read_station_file(new_station);
			break;
		}*/
		case 0: {
			return 0;
		}
		default:
			cout << "incorrect input! try again " << endl;
			break;
		}
	}
}