#pragma once
#include <iostream>

using namespace std;

template <typename T>
T check_input(T min, T max)
{
    T x;
    while ((cin >> x).fail() || (cin).peek() != '\n' || x < min || x > max)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nenter the correct data (" << min << " - " << max << ") ";
    }
    return x;
}

template<class C, typename T>
bool contains(C& c, T& t) {
    return find(begin(c), end(c), t) != end(c);
};

class redirected_output
{
private:
	ostream& out;
	streambuf* buf;
public:
	redirected_output(ostream& src)
		:buf(src.rdbuf()), out(src)
	{}
	~redirected_output() {
		out.rdbuf(buf);
	}
	void redirect (ostream& dest) {
		out.rdbuf(dest.rdbuf());
	}
};