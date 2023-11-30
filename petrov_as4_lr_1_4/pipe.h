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
};

void pipe_input(pipe& new_pipe, int id);
void pipe_delete(unordered_map<int, pipe>& pipes, int id);
void pipe_edit(unordered_map<int, pipe>& pipes, int id);
void pipe_output(const unordered_map<int, pipe>& pipes);
void write_pipe_file(pipe new_pipe);
//void read_pipe_file(pipe& new_pipe);