#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename InputIterator, typename T>
InputIterator findd(InputIterator first, InputIterator last, const T& val);

int main(int argc, char *argv[])
{
        vector<int> nums;
        nums.push_back(3);
        nums.push_back(-10);
        nums.push_back(7);
        nums.push_back(21);
        nums.push_back(4);

        cout << *findd(nums.begin(), nums.end(), 21) << endl;
        return 0;
}

template <typename InputIterator, typename T>
InputIterator findd(InputIterator first, InputIterator last, const T& val)
{
        while (first != last) {
                if (*first == val)
                        return first;
                ++first;
        }
        return last;
}
