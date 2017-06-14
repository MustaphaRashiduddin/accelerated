#ifndef _PERSON_H
#define _PERSON_H

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
                friend std::ostream& operator<< (std::ostream& stream, const Person& person) 
                {
                        return stream << person.name << ", " << person.age; 
                }
                friend bool operator==(const Person& lhs, const Person& rhs)
                {
                        return lhs.name == rhs.name && lhs.age == rhs.age;
                }

        public:
                Person() { name = 0; }
                Person(const char* name, int age);

                // stack pass
                Person(const Person& person) { copy(person); }

                ~Person() { destroy(); }

                // stack pass
                Person& operator=(const Person& rhs);

                void print() { std::cerr << "name: " << name <<  " age: " << age << std::endl; }

};

#endif
