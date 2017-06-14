#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::domain_error;
using std::sort;

template<class It>
double median(It first, It const last, size_t n);

template<class T>
T median(vector<T> v);
int main(int argc, char *argv[])
{
        double myints[] = {16.32, 2, 77, 29, 7};
        size_t n = sizeof(myints)/sizeof(*myints);
        vector<double> nums (myints, myints+n);
        cout << median(myints, myints+n, n) << endl;
        cout << median(nums.begin(), nums.end(), n) << endl;
        return 0;
}

template<class It>
double median(It first, It const last, size_t n)
{
        if (n == 0)
                throw domain_error("median of an empty vector");

        sort(first, last);

        size_t m = n/2;
        return n % 2 == 0 ? (first[m] + first[m-1]) / 2 : first[m];
}
