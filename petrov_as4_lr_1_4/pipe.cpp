#include "pipe.h"
#include "header.h"

#include <unordered_map>
#include <fstream>

using namespace std;

int pipe::ID = 1;

pipe::pipe()
{
	id = ID++;
}

istream& operator>>(istream& in, pipe& new_pipe){
	cout << "enter pipe name: ";
	in.ignore();
	getline(cin, new_pipe.pname);

	cout << "enter pipe length: ";
	new_pipe.length = check_input(0.0, 100000.0);

	cout << "enter pipe diameter: ";
	new_pipe.diameter = check_input(500, 1400);
	while (new_pipe.diameter != 500 and new_pipe.diameter != 700 and new_pipe.diameter != 1000 and new_pipe.diameter != 1400) {
		cout << "enter 500, 700, 1000 or 1400 " << endl;
		new_pipe.diameter = check_input(500, 1400);
	}

	cout << "is the pipe under repair? (1 - yes, 0 - no): ";
	new_pipe.repair = check_input(0, 1);
	return in;
}

ostream& operator<<(ostream& out, pipe& new_pipe) {
	out << "\npipe id is: " << new_pipe.getid() << endl;
	out << "pipe name is: " << new_pipe.pname << endl;
	out << "pipe length is: " << new_pipe.length << endl;
	out << "pipe diameter is: " << new_pipe.diameter << endl;
	out << "pipe under repair? " << new_pipe.repair << endl;
	out << "--------------------------------" << endl;
	return out;
}

ofstream& operator<<(ofstream& fout, pipe& new_pipe){
	fout << new_pipe.pname << endl << new_pipe.length << endl << new_pipe.diameter << endl << new_pipe.repair << endl;
	return fout;
}

ifstream& operator>>(ifstream& fin, pipe& new_pipe){
	fin.ignore();
	getline(fin, new_pipe.pname);
	fin >> new_pipe.length;
	fin >> new_pipe.diameter;
	fin >> new_pipe.repair;
	return fin;
}