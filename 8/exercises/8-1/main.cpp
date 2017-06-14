#include "Student_info.hpp"
#include "grade.hpp"
#include "median.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using std::find;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::transform;
using std::back_inserter;
using std::transform;
using std::ostream;
using std::string;
using std::accumulate;
using std::remove_copy;

bool did_all_hw(const Student_info&);
template <typename F>
void write_analysis(ostream&, const string&, F, const vector<Student_info>&, const vector<Student_info>&);
double average(const vector<double>&);
double average_grade(const Student_info&);
double optimistic_median(const Student_info&);
double average_analysis(const vector<Student_info>&);
double median_analysis(const vector<Student_info>&);
double optimistic_median_analysis(const vector<Student_info>&);
template <typename F>
double analysis(const vector<Student_info>&, F);

int main(int argc, char *argv[])
{
        // students who did and didnt do all their homework
        vector<Student_info> did, didnt;

        // read the student records and partition them
        Student_info student;
        while (read(cin, student)) {
                if (did_all_hw(student))
                        did.push_back(student);
                else
                        didnt.push_back(student);
        }

        // verify that the analyses will show us something
        if (did.empty()) {
                cout << "No student did all the homework!" << endl;
                return 1;
        }
        if (didnt.empty()) {
                cout << "Every student did all the homework!" << endl;
                return 1;
        }

        // do the analysis
        write_analysis(cout, "median", grade_aux, did, didnt);
        write_analysis(cout, "average", average_grade, did, didnt);
        write_analysis(cout, "optimistic_median", optimistic_median, did, didnt);

        return 0;

}

bool did_all_hw(const Student_info& s)
{
        return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

double average(const vector<double>& v)
{
        return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
        return grade(s.midterm, s.final, average(s.homework));
}

double optimistic_median(const Student_info& s)
{
        vector<double> nonzero;
        remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

        if (nonzero.empty())
                return grade(s.midterm, s.final, 0);
        else
                return grade(s.midterm, s.final, median(nonzero));
}

template <typename F>
void write_analysis(ostream& out, const string& name, F f, const vector<Student_info>& did, const vector<Student_info>& didnt)
{
        out << name << ": median(did) = " << analysis(did, f) << ", median(didnt) = " << analysis(didnt, f) << endl;
}

template <typename F>
double analysis(const vector<Student_info>& students, F f)
{
        vector<double> grades;

        transform(students.begin(), students.end(), back_inserter(grades), f);
        return median(grades);
}
