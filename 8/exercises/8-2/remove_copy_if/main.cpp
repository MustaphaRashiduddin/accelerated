#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::remove_copy_if;

bool isOdd(int);

template <typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator remove_copyy_if(InputIterator first, InputIterator last, OutputIterator d_first, Predicate pred);

int main(int argc, char *argv[])
{
        int myints[] = {1,2,3,4,5,6,7,8,9};
        vector<int>myvector(9);
        remove_copyy_if(myints, myints+8, myvector.begin(), isOdd);
        for(vector<int>::const_iterator iter=myvector.begin(); iter!=myvector.end(); iter++)
                cout << " " << *iter;
        return 0;
}

bool isOdd(int n)
{
        return n%2 == 1;
}

template <typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator remove_copyy_if(InputIterator first, InputIterator last, OutputIterator d_first, Predicate pred)
{
        while (first != last) {
                if (!pred(*first)) {
                        *d_first = *first;
                        ++d_first;
                }
                ++first;
        }
        return d_first;
}
