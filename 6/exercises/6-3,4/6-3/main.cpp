#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::copy;
using std::back_inserter;
using std::list;

template<typename InputIt, typename OutputIt>
OutputIt copyy(InputIt first, InputIt last, OutputIt d_first);

int main(int argc, char *argv[])
{
        vector<int> u(10, 100);
        list<int> v;
        copyy(u.begin(), u.end(), back_inserter(v));
        for (list<int>::const_iterator iter=v.begin(); iter!=v.end(); iter++)
                cout << *iter << endl;
        return 0;
}

template<typename InputIt, typename OutputIt>
OutputIt copyy(InputIt first, InputIt last, OutputIt d_first)
{
        while (first != last) {
                *d_first = *first;
                ++first;
                ++d_first;
        }
        return d_first;
}
