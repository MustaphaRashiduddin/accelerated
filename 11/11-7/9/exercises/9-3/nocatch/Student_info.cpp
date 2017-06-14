#include "Student_info.hpp"
#include <iostream>
#include <limits>

using std::istream;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::numeric_limits;
using std::streamsize;

istream& read_hw(std::istream& in, std::vector<double>& hw);

Student_info::Student_info(): midterm(0), final(0) {}

Student_info::Student_info(std::istream& is) {read(is);}

istream& Student_info::read(istream& in)
{
        cout << "input name, midterm and final" << endl;
        in >> n >> midterm >> final;

        cout << "enter all homeworks ending with an invalid" << endl;
        read_hw(in, homework);
        return in;
}

istream& read_hw(std::istream& in, std::vector<double>& hw)
{
        if (in) {
                // get rid of previous contents
                hw.clear();

                // read homework grades
                double x;
                while (in >> x)
                        hw.push_back(x);

                // clear the stream so that input will work for the next student
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        return in;
}


bool compare(const Student_info& x, const Student_info& y)
{
        return x.name() < y.name();
}
