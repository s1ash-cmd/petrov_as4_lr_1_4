#include "gts.h"
#include "header.h"
#include "pipe.h"
#include "station.h"

#include <iostream>
#include <fstream>

using namespace std;


void gts::printmenu() {
	cout << "\n_____menu_____" << endl;
	cout << "1) add pipe" << endl;
	cout << "2) add station" << endl;
	cout << "3) see all objets" << endl;
	cout << "4) edit pipes" << endl;
	cout << "5) edit stations" << endl;
	cout << "6) delete pipes" << endl;
	cout << "7) delete stations" << endl;
	cout << "8) save to file" << endl;
	cout << "9) load from file" << endl;
	cout << "0) exit" << endl;
	cout << "===============================" << endl;
	cout << "enter a number ";
}

void gts::pipe_output(unordered_map<int, pipe> pipes) {
	if (pipes.empty()) {
		cout << "no pipes found" << endl;
	}
	else {
		cout << "pipes:" << endl;
		for (auto& new_pipe : pipes) {
			cout << new_pipe.second;
		}
	}
}

void gts::station_output(unordered_map<int, station> stations) {
	if (stations.empty()) {
		cout << "no station found" << endl;
	}
	else {
		cout << "stations:" << endl;
		for (auto& new_station : stations) {
			cout << new_station.second;
		}
	}
}

vector<int> gts::pipe_select(unordered_map<int, pipe> pipes) {
	vector <int> selectedpipes;
	cout << "\n1) select by name" << endl;
	cout << "2) select by status" << endl;

	int action = check_input(0, 2);
	switch (action) {
	case 1: {
		string search_name;
		cout << "enter pipe name: ";
		cin.ignore();
		getline(cin, search_name);
		for (auto& new_pipe : pipes) {
			if (new_pipe.second.pname.find(search_name) != string::npos) {
				selectedpipes.push_back(new_pipe.second.getid());
			}
		}
		break;
	}
	case 2: {
		cout << "enter repair status (0 - 1) ";
		bool status = check_input(0, 1);

		for (auto& new_pipe : pipes) {
			if (new_pipe.second.repair == status) {
				selectedpipes.push_back(new_pipe.second.getid());
			}
		}
		break;
	}
	}
	return selectedpipes;
}

void gts::pipe_edit(unordered_map <int, pipe>& pipes) {
	cout << "\n1) edit all pipes" << endl;
	cout << "2) select pipes to edit" << endl;

	int action = check_input(1, 2);

	switch (action) {
	case 1: {
		if (pipes.empty()) {
			cout << "no pipes found" << endl;
		}
		else {
			for (auto& new_pipe : pipes) {
				new_pipe.second.repair = !new_pipe.second.repair;
			}
			cout << "\nall pipes status has been changed" << endl;
		}
		break;
	}
	case 2: {
		if (pipes.empty()) {
			cout << "no pipes found" << endl;
		}
		else {
			vector <int> selectedpipes = pipe_select(pipes);
			if (selectedpipes.empty()) {
				cout << "no items selected" << endl;
			}
			else {
				for (auto& new_pipe : pipes) {
					int i = new_pipe.second.getid();
					if (contains(selectedpipes, i)) {
						new_pipe.second.repair = !new_pipe.second.repair;
					}
				}
				cout << "selected pipes status has been changed" << endl;
			}
			break;
		}
	}
	}
}

void gts::pipe_delete(unordered_map<int, pipe>& pipes) {
	cout << "\n1) delete all pipes" << endl;
	cout << "2) select pipes to delete" << endl;

	int action = check_input(1, 2);

	switch (action) {
	case 1: {
		if (pipes.empty()) {
			cout << "no pipes found" << endl;
		}
		else {
			pipes.clear();
			cout << "all pipes have been deleted" << endl;
		}
		break;
	}
	case 2: {
		if (pipes.empty()) {
			cout << "no pipes found" << endl;
		}
		else {
			vector <int> selectedpipes = pipe_select(pipes);
			if (selectedpipes.empty()) {
				cout << "no items selected" << endl;
			}
			else {
				int i = 0;
				for (int i : selectedpipes) {
					pipes.erase(i);
				}
				cout << "selected pipes have been deleted" << endl;
			}
			break;
		}
	}
	}
}

vector<int> gts::station_select(unordered_map<int, station> stations) {
	vector <int> selectedstations;
	cout << "\n1) select by name" << endl;
	cout << "2) select by status" << endl;

	int action = check_input(0, 2);
	switch (action) {
	case 1: {
		string search_name;
		cout << "enter station name: ";
		cin.ignore();
		getline(cin, search_name);
		for (auto& new_station : stations) {
			if (new_station.second.sname.find(search_name) != string::npos) {
				selectedstations.push_back(new_station.second.getid());
			}
		}
		break;
	}
	case 2: {
		cout << "enter efficiency (%) ";
		int efficiency = check_input(0, 100);

		for (auto& new_station : stations) {
			if (100 - efficiency == new_station.second.eff) {
				selectedstations.push_back(new_station.second.getid());
			}
		}
		break;
	}
	}
	return selectedstations;
}

void gts::station_edit(unordered_map<int, station>& stations) {
	cout << "\n1) edit all stations" << endl;
	cout << "2) select stations to edit" << endl;

	int action = check_input(1, 2);

	switch (action) {
	case 1: {
		if (stations.empty()) {
			cout << "no stations found" << endl;
		}
		else {
			for (auto& new_station : stations) {
				cout << "station name is: " << new_station.second.sname << endl;
				cout << "total number of workshops: " << new_station.second.number_of_workshops << endl;
				cout << "number of workshops in work: " << new_station.second.workshops_in_work << endl;
				cout << "enter new number of workshops in work: ";

				new_station.second.workshops_in_work = check_input(0, 1000);

				while (new_station.second.number_of_workshops < new_station.second.workshops_in_work) {
					cout << "the number of working workshops cant be more than the total number of workshops" << endl << "enter again ";
					new_station.second.workshops_in_work = check_input(0, 1000);
				}
				new_station.second.eff = round(double(new_station.second.workshops_in_work) / double(new_station.second.number_of_workshops) * 100);
				cout << "eff of the station: " << new_station.second.eff << "%" << endl;
				cout << "--------------------------------" << endl;
			}
			cout << "all stations have been edited" << endl;
		}
		break;
	}
	case 2: {
		if (stations.empty()) {
			cout << "no stations found" << endl;
		}
		else {
			vector <int> selectedstations = station_select(stations);
			if (selectedstations.size() == 0) {
				cout << "no items selected" << endl;
			}
			else {
				for (auto& new_station : stations) {
					int i = new_station.second.getid();
					if (contains(selectedstations, i)) {
						cout << "station name is: " << new_station.second.sname << endl;
						cout << "total number of workshops: " << new_station.second.number_of_workshops << endl;
						cout << "number of workshops in work: " << new_station.second.workshops_in_work << endl;
						cout << "enter new number of workshops in work: ";

						new_station.second.workshops_in_work = check_input(0, 1000);

						while (new_station.second.number_of_workshops < new_station.second.workshops_in_work) {
							cout << "the number of working workshops cant be more than the total number of workshops" << endl << "enter again ";
							new_station.second.workshops_in_work = check_input(0, 1000);
						}
						new_station.second.eff = round(double(new_station.second.workshops_in_work) / double(new_station.second.number_of_workshops) * 100);
						cout << "eff of the station: " << new_station.second.eff << "%" << endl;
						cout << "--------------------------------" << endl;
					}
				}
				cout << "selected stations have been edited" << endl;
				break;
			}
		}
	}
	}
}

void gts::station_delete(unordered_map<int, station>& stations) {
	cout << "\n1) delete all stations" << endl;
	cout << "2) select stations to delete" << endl;

	int action = check_input(1, 2);

	switch (action) {
	case 1: {
		if (stations.empty()) {
			cout << "no stations found" << endl;
		}
		else {
			stations.clear();
			cout << "all stations have been deleted" << endl;
		}
		break;
	}
	case 2: {
		if (stations.empty()) {
			cout << "no stations found" << endl;
		}
		else {
			vector <int> selectedstations = station_select(stations);
			if (selectedstations.empty()) {
				cout << "no items selected" << endl;
			}
			else {
				int i = 0;
				for (int i : selectedstations) {
					stations.erase(i);
				}
				cout << "selected stations have been deleted" << endl;
			}
			break;
		}
	}
	}
}

void gts::data_write(unordered_map<int, pipe> pipes, unordered_map<int, station> stations) {
	ofstream fout;
	string filename;

	if (pipes.empty() and stations.empty()) {
		cout << "no data about pipes and stations" << endl;
	}

	else {
		cout << "enter file name: ";
		cin >> filename;

		fout.open(filename, ofstream::app, ofstream::trunc);
		if (fout.is_open()) {


			fout << pipes.size() << " " << stations.size() << endl;
			for (auto& new_pipe : pipes) {
				fout << new_pipe.second;
			}
			for (auto& new_station : stations) {
				fout << new_station.second;
			}
			cout << "data saved successfully" << endl;
		}
		else {
			cout << "file cant be opened" << endl;
		}
		fout.close();
	}
}

void gts::data_read(unordered_map<int, pipe>& pipes, unordered_map<int, station>& stations) {
	ifstream fin;
	string filename;
	string line;

	int pipecount;
	int stationcount;

	cout << "enter file name: ";
	cin >> filename;

	fin.open(filename, ifstream::app);
	if (fin.is_open()) {
		if (fin.peek() == ifstream::traits_type::eof()) {
			cout << "no data in file or the file name is incorrect" << endl;
		}
		else {
			fin >> pipecount >> stationcount;
			if (pipecount == 0) {
				cout << "There is no data about pipes. " << endl;
				for (int i = 1; i <= stationcount; i++) {
					station new_station;
					fin >> new_station;
					stations.insert({ new_station.getid(), new_station });
				}
			}
			else if (stationcount == 0) {
				cout << "There is no data about stations. " << endl;
				for (int i = 1; i <= pipecount; i++) {
					pipe new_pipe;
					fin >> new_pipe;
					pipes.insert({ new_pipe.getid(),new_pipe });
				}
			}
			else {
				for (int i = 1; i <= pipecount; i++) {
					pipe new_pipe;
					fin >> new_pipe;
					pipes.insert({ new_pipe.getid(),new_pipe });
				}
				for (int i = 1; i <= stationcount; i++) {
					station new_station;
					fin >> new_station;
					stations.insert({ new_station.getid(), new_station });
				}
			}
		}
	}
	else {
		cout << "File couldn't be open." << endl;
	}
}