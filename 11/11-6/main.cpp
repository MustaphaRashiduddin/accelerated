#include "vec.hpp"
#include <iostream>
#include <vector>
#include "person.hpp"

using std::cerr;
using std::endl;
using std::string;
using std::vector;

void p(Vec<string>& v);
void p(vector<string>& v);
void p(Vec<Person>& v);

int main(int argc, char *argv[])
{
        /*
         * Vec<string> v;
         * v.push_back("greetings");
         * v.push_back("people");
         * v.push_back("of");
         * v.push_back("the");
         * v.push_back("world");
         * v.push_back("bitches");
         */

        Vec<Person> v;
        v.push_back(Person("saif", 30));
        v.push_back(Person("lol", 10));

        p(v);

        return 0;
}

void p(Vec<Person>& v)
{
        for (Vec<Person>::const_iterator iter=v.begin(); iter!=v.end(); ++iter)
                cerr << iter->name << ", " << iter->age << endl;
        cerr << "---------------;" << endl;
}

void p(Vec<string>& v)
{
        for (Vec<string>::const_iterator iter=v.begin(); iter!=v.end(); ++iter)
                cerr << *iter << endl;
        cerr << "---------------;" << endl;
}

void p(vector<string>& v)
{
        for (vector<string>::const_iterator iter=v.begin(); iter!=v.end(); ++iter)
                cerr << *iter << endl;
        cerr << "---------------;" << endl;
}
