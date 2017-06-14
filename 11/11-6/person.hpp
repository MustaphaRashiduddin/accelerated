#ifndef _PERSON_H_
#define _PERSON_H_

#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <string.h>

class Person
{
        public:
                const char* name;
                int age;

                void destroy() { free((char*)name); }
                void copy(const Person& person);
                friend std::ostream& operator<< (std::ostream& stream, const Person& person) { return stream << person.name << ", " << person.age; }

        public:
                Person() { name = 0; }
                Person(const char* name, int age);
                Person(const Person& person) { copy(person); }

                ~Person() {
                        destroy(); 
                }

                Person& operator=(const Person& rhs);

                void print() { std::cerr << "name: " << name <<  " age: " << age << std::endl; }

};

#endif
