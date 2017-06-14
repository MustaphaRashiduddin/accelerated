#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::remove;

template <typename ForwardIterator, typename T>
ForwardIterator removee(ForwardIterator, ForwardIterator, const T&);

int main(int argc, char *argv[])
{
        int myints[] = {10,20,30,30,20,10,10,20};

        // bounds of range
        int *pbegin = myints;
        int *pend = myints + sizeof(myints)/sizeof(int);

        pend = removee(pbegin, pend, 20);

        cout << "range contains:";
        for (int *p=pbegin; p!=pend; ++p)
                cout << " " << *p;
        cout << endl;

        return 0;
}

template <typename ForwardIterator, typename T>
ForwardIterator removee(ForwardIterator first, ForwardIterator last, const T& val)
{
        ForwardIterator d_first = first;
        while (first != last) {
                *d_first = *first;
                if (*first != val) {
                        *d_first = *first;
                        ++d_first;
                }
                ++first;
        }
        return d_first;
}
