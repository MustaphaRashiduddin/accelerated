#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

class Student_info {
        private:
                std::string n;
                double midterm, final;
                std::vector<double> homework;
        public:
                Student_info(); // construct an empty Student_info object
                Student_info(std::istream&);  // construct one by reading a stream
                bool valid() const {return !homework.empty();}
                double grade() const;
                std::istream& read(std::istream&);
                std::string name() const {return n;}
};

bool compare(const Student_info&, const Student_info&);

#endif
