#include <iostream>
#include <fstream>
#include <unordered_map>

#include "pipe.h"
#include "header.h"

void pipe_input(pipe& new_pipe, int id) {
	new_pipe.id = id;

	cout << "enter pipe name: ";
	cin.ignore();
	getline(cin, new_pipe.pname);

	cout << "enter pipe length: ";
	new_pipe.length = check_input(0.0, 100000.0);

	cout << "enter pipe diameter: ";
	new_pipe.diameter = check_input(400, 1800);

	cout << "is the pipe under repair? (1 - yes, 0 - no): ";
	new_pipe.repair = check_input(0, 1);
}

void pipe_delete(unordered_map<int, pipe>& pipes, int id) {
	auto it = pipes.find(id);
	if (it != pipes.end()) {
		pipes.erase(it);
		cout << "pipe with id " << id << "has been deleted" << endl;
	}
	else {
		cout << "no pipe found with that id " << endl;
	}
}

void pipe_edit(unordered_map<int, pipe>& pipes, int id) {

	auto it = pipes.find(id);
	if (it != pipes.end()) {
		pipe& edited_pipe = it->second;

		cout << "enter new pipe name: ";
		cin.ignore();
		getline(cin, edited_pipe.pname);

		cout << "enter new pipe length: ";
		edited_pipe.length = check_input(0.0, 100000.0);

		cout << "enter new pipe diameter: ";
		edited_pipe.diameter = check_input(400, 1800);

		cout << "is the pipe under repair? (1 - yes, 0 - no): ";
		edited_pipe.repair = check_input(0, 1);

		cout << "pipe with id " << id << " edited successfully" << endl;
	}
	else {
		cout << "pipe with id " << id << " not found" << endl;
	}

}

void pipe_output(const unordered_map<int, pipe>& pipes, bool inRepair, const string& nazvanie) {
	if (pipes.empty()) {
		cout << "no pipes found" << endl;
	}
	else {
		for (const auto& pair : pipes) {
			const pipe& new_pipe = pair.second;
			bool matchName = nazvanie.empty() || new_pipe.sravnenie(nazvanie);
			bool matchRepair = inRepair || new_pipe.repair;

			if (matchName && matchRepair) {
				cout << "\npipe id is " << new_pipe.id << endl;
				cout << "pipe name is " << new_pipe.pname << endl;
				cout << "pipe length is " << new_pipe.length << endl;
				cout << "pipe diameter is " << new_pipe.diameter << endl;
				cout << "pipe under repair? " << new_pipe.repair << endl;
			}
		}
	}
}


void write_pipe_file(pipe new_pipe) {
	ofstream file_out;

	file_out.open("file.txt");
	if (!new_pipe.pname.empty()) {
		if (file_out.is_open()) {
			file_out << "pipe: " << endl;
			file_out << new_pipe.pname << endl << new_pipe.length << endl
				<< new_pipe.diameter << endl << new_pipe.repair << endl;
		}
		else {
			cout << "couldnt open file" << endl;
		}
		file_out.close();
	}
	else {
		cout << "no pipe found" << endl;
	}
}

//void read_pipe_file(pipe& new_pipe) {
//	ifstream file_in;
//	string pstr;
//	file_in.open("file.txt");
//	if (file_in.is_open()) {
//		while (getline(file_in, pstr)) {
//			if (pstr == "pipe: ") {
//				cout << pstr << endl;
//				file_in >> new_pipe.pname;
//				file_in >> new_pipe.length;
//				file_in >> new_pipe.diameter;
//				file_in >> new_pipe.repair;
//				pipe_output(pipes);
//			}
//		}
//		file_in.close();
//	}
//	else {
//		cout << "file couldnt be open " << endl;
//	}
//}