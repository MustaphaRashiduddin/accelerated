#include <stdexcept>
#include <vector>
#include "Student_info.hpp"
#include "median.hpp"

using std::domain_error;
using std::vector;

// definitions for the grade functions from 4.1/52, 4.1.2/54, 4.2.2/63 
double grade(double midterm, double final, double homework)
{
        return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because median does so for us.
double grade(double midterm, double final, const std::vector<double>& hw)
{
        if (hw.size() == 0)
                throw domain_error("student has done no homework");
        return grade(midterm, final, median(hw));
}

double Student_info::calcGrade()
{
        return ::grade(midterm, final, homework);
}

double Student_info::grade() const
{
        return g;
}
