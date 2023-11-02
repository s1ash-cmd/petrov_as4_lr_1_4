#include <iostream>
#include <fstream>

#include "pipe.h"
#include "check_input.h"

void pipe_input(pipe& new_pipe) {
	cout << "enter pipe name: ";
	cin.ignore();
	getline(cin, new_pipe.pname);

	cout << "enter pipe length: ";
	check_input_double(new_pipe.length);

	cout << "enter pipe diameter: ";
	check_input_double(new_pipe.diameter);

	cout << "is the pipe under repair? (1 - yes, 0 - no): ";
	check_input_bool(new_pipe.repair);
}

void pipe_output(const pipe& new_pipe) {
	if (new_pipe.pname.empty()) {
		cout << "no pipe found";
	}

	else {
		cout << "pipe name is " << new_pipe.pname << endl;
		cout << "pipe length is " << new_pipe.length << endl;
		cout << "pipe diameter is " << new_pipe.diameter << endl;
		cout << "pipe under repair? " << new_pipe.repair << endl;
	}
};

void pipe_change_status(pipe& new_pipe) {
	new_pipe.repair = !new_pipe.repair;
	cout << "pipe status has been changed" << endl;
	cout << "new pipe repair status is: " << new_pipe.repair << endl;
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

void read_pipe_file(pipe& new_pipe) {
	ifstream file_in;
	string pstr;
	file_in.open("file.txt");
	if (file_in.is_open()) {
		while (getline(file_in, pstr)) {
			if (pstr == "pipe: ") {
				cout << pstr << endl;
				file_in >> new_pipe.pname;
				file_in >> new_pipe.length;
				file_in >> new_pipe.diameter;
				file_in >> new_pipe.repair;
				pipe_output(new_pipe);
			}
		}
		file_in.close();
	}
	else {
		cout << "file couldnt be open " << endl;
	}
}