#pragma once
#include <string>

using namespace std;

class pipe {
public:
	int id;
	string pname;
	double length;
	double diameter;
	bool repair;

	bool sravnenie(const string& nazvanie) const {
		return pname.find(nazvanie) != string::npos;
	}
};

void pipe_input(pipe& new_pipe, int id);
void pipe_delete(unordered_map<int, pipe>& pipes, int id);
void pipe_edit(unordered_map<int, pipe>& pipes, int id);
void pipe_output(const unordered_map<int, pipe>& pipes, const string& nazvanie = "", bool inrepair = true, bool notinrepair = true);
void write_pipe_file(pipe new_pipe);
//void read_pipe_file(pipe& new_pipe);