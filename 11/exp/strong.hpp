// #include "person.hpp"
#include <memory>

using std::allocator;

template <class T> void func()
{
        allocator<T> personAllocator;
        int n=3;
        Person* persons = personAllocator.allocate(n);
        personAllocator.construct(persons, Person("sayf", 21));
        personAllocator.construct(&persons[1], Person("ali", 11));
        persons->print();
        persons[1].print();
        personAllocator.destroy(&persons[1]);
        personAllocator.destroy(persons);
        personAllocator.deallocate(persons, n);
}
