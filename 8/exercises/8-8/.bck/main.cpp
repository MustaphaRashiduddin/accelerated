#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template<class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
        while (begin < end) {
                // find the midpoint of the range
                Ran mid = begin + (end - begin) / 2;
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

int main(int argc, char *argv[])
{
        vector<int> v;
        v.push_back(1);
        v.push_back(3);
        v.push_back(10);
        v.push_back(13);
        v.push_back(18);
        v.push_back(21);
        return 0;
}
