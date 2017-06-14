#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using std::transform;
using std::cout;
using std::endl;
using std::vector;
using std::plus;
using std::back_inserter;

template <typename InputIterator, typename OutputIterator, class UnaryOperator>
OutputIterator transformm(InputIterator, InputIterator, OutputIterator, UnaryOperator);

int op_increase(int i) {return ++i;}

int main(int argc, char *argv[])
{
        vector<int> foo;        
        vector<int> bar;

        // set some vals:
        for (int i=1; i<6; i++)
                foo.push_back(i*10);              // foo: 10 20 30 40 50

        // bar.resize(foo.size());                   // allocate space

        // transform(foo.begin(), foo.end(), back_inserter(bar), op_increase);
        transformm(foo.begin(), foo.end(), back_inserter(bar), op_increase);
                                                  // bar: 11 21 31 41 51

        cout << "foo contains:";
        for (vector<int>::iterator it=bar.begin(); it!=bar.end(); it++)
                cout << ' ' << *it;
        cout << endl;

        return 0;
}

template <typename InputIterator, typename OutputIterator, class UnaryOperator>
OutputIterator transformm(InputIterator first, InputIterator last, OutputIterator result, UnaryOperator op)
{
        while (first != last) {
                *result = op(*first);
                ++result; ++first;
        }
        return result;
}
