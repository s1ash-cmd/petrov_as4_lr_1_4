#pragma once
#include <string>

using namespace std;

class pipe {
	int id;
public:
	string pname = "";
	double length = 0;
	double diameter = 0;
	bool repair = false;
	bool used = false;

	static int ID;
	pipe();

	friend istream& operator >> (istream& in, pipe& new_pipe);
	friend ostream& operator << (ostream& out, pipe& new_pipe);
	friend ofstream& operator << (ofstream& fout, pipe& new_pipe);
	friend ifstream& operator >> (ifstream& fin, pipe& new_pipe);

	int getid() { return id; };
};