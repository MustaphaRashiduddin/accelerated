#include "person.hpp"

void Person::copy(const Person& person)
{
        this->name = (const char*)malloc(strlen(person.name)+1);
        strcpy((char*)this->name, person.name);
        this->age = person.age;
}

Person::Person(const char* name, int age)
{
        this->name = (const char*)malloc(strlen(name)+1);
        strcpy((char*)this->name, name);
        this->age = age;
}

Person& Person::operator=(const Person& rhs)
{
        if (&rhs != this) {
                destroy();
                copy(rhs);
        }
        return *this;
}
