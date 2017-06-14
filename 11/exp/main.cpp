#include "person.hpp"
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "strong.hpp"

using std::string;
using std::cout;
using std::endl;
using std::allocator;
using std::vector;

int main(int argc, char **argv)
{
        /*
         * allocator<Person> personAllocator;
         * int n=3;
         * Person* persons = personAllocator.allocate(n);
         * personAllocator.construct(persons, Person("sayf", 21));
         * personAllocator.construct(&persons[1], Person("ali", 11));
         * persons->print();
         * persons[1].print();
         * personAllocator.destroy(&persons[1]);
         * personAllocator.destroy(persons);
         * personAllocator.deallocate(persons, n);
         */
        func();

        return 0;
}
