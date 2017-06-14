#ifndef _VEC_H_
#define _VEC_H_

#include <cstddef>
#include <memory>

template <class T> class Vec 
{

        public:
                // data-member interface
                typedef T* iterator;
                typedef const T* const_iterator;
                typedef std::size_t size_type;
                typedef T value_type;

        private:
                iterator data;
                iterator avail;
                iterator limit;

                // allocate and initialize the underlying array
                void create();
                void create(size_type, const T&);
                void create(const_iterator, const_iterator);

                // facilities for memory allocation
                std::allocator<T> alloc; // object to handle memory allocation

                // support functions for push_back
                void grow();
                void unchecked_append(const T&);

                // destroy the elements in the array and free the memory
                void uncreate();

        public:
                // constructors
                Vec() { create(); }
                explicit Vec(size_type n, const T& t = T()) { create(n, t); }
                Vec(const Vec& v) { create(v.begin(), v.end()); }


                // destructor
                ~Vec() { uncreate(); }

                // main interface
                size_type size() const { return limit - data; }
                void push_back(const T& val) {
                        if (avail == limit)     // get space if needed
                                grow();
                        unchecked_append(val);  // append the new element
                }
                
                // overloaded operators
                T& operator[](size_type i) { return data[i]; }
                const T& operator[](size_type i) const { return data[i]; }

                Vec& operator=(const Vec&);

                // return iterators
                iterator begin() { return data; }
                const iterator begin() const { return data; }

                iterator end() { return limit; }
                const iterator end() const { return limit; }

};

#endif
