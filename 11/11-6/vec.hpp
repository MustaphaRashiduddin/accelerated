#ifndef _VEC_HPP
#define _VEC_HPP

#include <cstddef>
#include <memory>
#include <iostream>

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
                void create() { data = avail = limit = 0; } 
                void create(size_type, const T&);
                void create(const_iterator, const_iterator);

                // facilities for memory allocation
                std::allocator<T> alloc; // object to handle memory allocation

                // support functions for push_back
                void grow();
                void unchecked_append(const T& val) { alloc.construct(avail++, val); }

                // support functions for erase
                void shrink();

                // destroy the elements in the array and free the memory
                void uncreate();

        public:
                // constructors
                Vec() { create(); }
                // Vec(); 
                explicit Vec(size_type n, const T& t = T()) { create(n, t); }
                Vec(const Vec& v) { create(v.begin(), v.end()); }


                // destructor
                ~Vec() { uncreate(); }
                // ~Vec();

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

                iterator end() { return avail; }
                const iterator end() const { return avail; }

                iterator erase(iterator);
                // void erase(iterator);

                void clear() { uncreate(); }
};

template <class T> void Vec<T>::uncreate()
{
        if (data) {
                // destroy (in reverse order) the elements that were constructed
                iterator it = avail;
                while (it != data)
                        alloc.destroy(--it);

                // return all the space that was allocated
                alloc.deallocate(data, limit-data);
        }

        // reset pointers to indicate that the Vec is empty again
        data = limit = avail = 0;
}

template <class T> Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
        // check for self-assignment
        if(&rhs != this) {

                // free the array in the left hand side
                uncreate();

                // copy elements from the right-hand to the left-hand side
                create(rhs.begin(), rhs.end());
        }

        return *this;
}

template <class T> void Vec<T>::create(size_type n, const T& val)
{
        data = alloc.allocate(n);
        limit = avail = data + n;
        uninitialized_fill(data, limit, val);
}

template <class T> void Vec<T>::create(const_iterator i, const_iterator j)
{
        data = alloc.allocate(j-i);
        limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T> void Vec<T>::grow()
{
        // when growing allocate twice as much space as currently in use
        size_type new_size = std::max(2 * (limit - data), std::ptrdiff_t(1));

        // allocate new space and copy existing elements to the new space
        iterator new_data = alloc.allocate(new_size);
        iterator new_avail = std::uninitialized_copy(data, avail, new_data);

        // return the old space
        uncreate();

        // reset the pointers to the newly allocated space
        data = new_data;
        avail = new_avail;
        limit = data + new_size;
}

template <class T> void Vec<T>::shrink()
{
        // shrinking to half size
        size_type new_size = (limit-data)/2;

        // allocate new space and copy existing elements to the new space
        iterator new_data = alloc.allocate(new_size);
        iterator new_avail = std::uninitialized_copy(data, avail, new_data);

        // return the old space
        uncreate();

        // reset the pointers to the newly allocated space
        data = new_data;
        avail = new_avail;
        limit = data + new_size;
}

template <class T> typename Vec<T>::iterator Vec<T>::erase(iterator it)
{
        iterator temp = it;
        while (it != avail-1) {
                *it = *(it+1);
                ++it;
        }

        // reduce avail by one and destroy extra mem space
        alloc.destroy(--avail);

        if (limit-avail == avail-data) {
                size_type temp_pos = temp - data;
                shrink();
                temp = data + temp_pos;
        }

        // temp = data+1;
        return temp;
}

#endif
