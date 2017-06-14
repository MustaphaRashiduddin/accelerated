#include <iostream>
#include <functional>
#include <numeric>

using std::cout;
using std::accumulate;
using std::endl;

int myfunction(int x, int y) {return x+2*y;}
struct myclass {
        int operator()(int x, int y) {return x+3*y;}
} myobject;

template <class InputIterator, class T>
T accumulatee(InputIterator, InputIterator, T);

int main(int argc, char *argv[])
{
        int init = 100;
        int numbers[] = {10, 20, 30};

        cout << "using default to accumulate: ";
        cout << accumulatee(numbers, numbers+3, init) << endl; 

        return 0;
}

template <class InputIterator, class T>
T accumulatee(InputIterator first, InputIterator last, T init)
{
        while (first != last) {
                init += *first;
                ++first;
        }
        return init;
}
