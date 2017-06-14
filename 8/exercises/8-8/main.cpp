#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template<class T>
bool binary_search(typename vector<T>::const_iterator begin, typename vector<T>::const_iterator end, const T& x);

int main(int argc, char *argv[])
{
        vector<int> v;
        v.push_back(1);
        v.push_back(3);
        v.push_back(10);
        v.push_back(13);
        v.push_back(18);
        v.push_back(21);
        cout << binary_search(v.begin(), v.end(), 18) << endl;
        return 0;
}

template<class T>
bool binary_search(typename vector<T>::const_iterator begin, typename vector<int>::const_iterator end, const T& x)
{
        while (begin < end) {
                // find the midpoint of the range
                typename vector<T>::const_iterator mid = begin + (end - begin) / 2;
                // see which part of the range contains x; keep looking only in that part
                if (x < *mid)
                        end = mid;
                else if (*mid < x)
                        begin = mid + 1;
                // if we got here, then *mid == x so we're done
                else return true;
        }
        return false;
}

