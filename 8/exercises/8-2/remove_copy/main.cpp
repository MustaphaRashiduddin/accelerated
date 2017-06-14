#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::remove_copy;
using std::vector;

template <typename InputIterator, typename OutputIterator, typename T>
OutputIterator remove_copyy(InputIterator, InputIterator, OutputIterator, const T&);

int main(int argc, char *argv[])
{
        int myints[] = {10, 20, 30, 30, 20, 10, 10, 20};
        vector<int> myvector(8);

        remove_copyy(myints, myints+8, myvector.begin(), 20);

        cout << "myvector contains:";
        for (vector<int>::const_iterator iter=myvector.begin(); iter!=myvector.end(); iter++)
                cout << ' ' << *iter;
        cout << endl;

        return 0;
}

template <typename InputIterator, typename OutputIterator, typename T>
OutputIterator remove_copyy(InputIterator first, InputIterator last, OutputIterator result, const T& val)
{
        while (first != last) {
                if (*first != val) {
                        *result = *first;
                        ++result;
                }
                ++first;
        }
        return result;
}
