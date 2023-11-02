#pragma once
#include <string>

using namespace std;

class pipe {
public:
	string pname;
	double length;
	double diameter;
	bool repair;
};

void pipe_input(pipe& new_pipe);
void pipe_output(const pipe& new_pipe);
void pipe_change_status(pipe& new_pipe);
void write_pipe_file(pipe new_pipe);
void read_pipe_file(pipe& new_pipe);