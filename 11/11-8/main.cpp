#include <iostream>
#include "vec.hpp"
#include "list.hpp"
#include "person.hpp"

using std::cerr;
using std::endl;

int main(int argc, char *argv[])
{
        List<Person> l;
        l.push_back(Person("saif", 31));
        l.push_back(Person("ali", 28));
        l.push_back(Person("bombs", 20));
        l.push_back(Person("zoo", 13));
        l.push_back(Person("tom", 100));
        l.push_back(Person("mano", 13));

        for (List<Person>::iterator it=l.begin(); it!=l.end(); it++) {
                cerr << *it << endl;
        }

/*
 *         List<Person>::iterator it=l.begin();
 *         it++;
 *         cerr << *it << endl;
 *         it = l.begin();
 *         cerr << *it << endl;
 *
 *         List<Person>::iterator lol = it;
 *         lol++;
 *         cerr << *lol;
 */

        return 0;
}
