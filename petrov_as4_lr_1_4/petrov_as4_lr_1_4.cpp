#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

#include "header.h"
#include "pipe.h"
#include "station.h"

using namespace std;

int main() {
	int nextpipeid = 1;
	int nextstationid = 1;
	unordered_map <int, pipe> pipes;
	unordered_map <int, station> stations;

	for (;;) {
		cout << "\n_____menu_____" << endl;
		cout << "1) working with pipes" << endl;
		cout << "2) working with stations" << endl;
		cout << "3) see all objets" << endl;
		cout << "4) edit pipe status" << endl;
		cout << "5) edit workstations in work" << endl;
		cout << "6) save to file" << endl;
		cout << "7) load from file" << endl;
		cout << "0) exit" << endl;
		cout << "===============================" << endl;
		cout << "enter a number ";

		int choice = check_input(0, 7);

		switch (choice) {
		case 1: {
			cout << "\n1) add" << endl;
			cout << "2) edit" << endl;
			cout << "3) delete" << endl;
			cout << "0) go back" << endl;
			cout << "enter a number ";
			pipe new_pipe;

			int choicepipe = check_input(0, 3);

			switch (choicepipe) {
			case 1: {
				pipe_input(new_pipe, nextpipeid);
				pipes[nextpipeid++] = new_pipe;
				break;
			}
			case 2: {
				if (pipes.empty()) {
					cout << "no pipes found" << endl;
				}

				else {
					cout << "\navailable pipes:";
					for (const auto& pair : pipes) {
						cout << " " << pair.first;
					}

					cout << "\nenter the id of the pipe to edit ";
					int da = check_input(1, nextpipeid - 1);
					pipe_edit(pipes, new_pipe.id);
				}
				break;
			}
			case 3: {
				if (pipes.empty()) {
					cout << "no pipes found" << endl;
				}
				else {
					cout << "\navailable pipes:";
					for (const auto& pair : pipes) {
						cout << " " << pair.first;
					}

					cout << "\nenter the id of the pipe to delete ";
					int da = check_input(1, nextpipeid - 1);
					pipe_delete(pipes, da);
				}
				break;
			}
			case 0: {
				break;
			}
			}
			break;
		}
		case 2: {
			cout << "\n1) add" << endl;
			cout << "2) edit" << endl;
			cout << "3) delete" << endl;
			cout << "enter a number ";
			station new_station;

			int choicestation = check_input(0, 3);

			switch (choicestation) {
			case 1: {
				station_input(new_station, nextstationid);
				stations[nextstationid++] = new_station;
				break;
			}
			case 2: {
				if (stations.empty()) {
					cout << "no stations found" << endl;
				}

				else {
					cout << "\navailable stations:";
					for (const auto& pair : stations) {
						cout << " " << pair.first;
					}

					cout << "\nenter the id of the station to edit ";
					int da = check_input(1, nextstationid - 1);
					station_edit(stations, new_station.id);
				}
				break;
			}
			case 3: {
				if (stations.empty()) {
					cout << "no stations found" << endl;
				}

				else {
					cout << "\navailable stations:";
					for (const auto& pair : stations) {
						cout << " " << pair.first;
					}

					cout << "\nenter the id of the station to delete ";
					int da = check_input(1, nextstationid - 1);
					station_delete(stations, da);
				}
				break;
			}
			case 0: {
				break;
			}
			}
			break;
		}
		case 3: {
			cout << "\npipes:" << endl;
			pipe_output(pipes);

			cout << "\nstations:" << endl;
			station_output(stations);
			break;
		}


			  /*case 4: {

					  break;
				  }
				  case 5: {

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