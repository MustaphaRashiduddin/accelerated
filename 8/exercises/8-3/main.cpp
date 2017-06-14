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

template <class Iterator>
double median(Iterator, Iterator, int);

int main(int argc, char *argv[])
{
        double myints[] = {16.32, 2, 77, 29, 7};
        vector<double> nums (myints, myints + sizeof(myints) / sizeof(double));

        // cout << median(nums.begin(), nums.end(), nums.size()) << endl;
        cout << median(nums.begin(), nums.end(), nums.size()) << endl;
        return 0;
}

template <class Iterator>
double median(Iterator first, Iterator last, int sz)
{
        if (sz == 0)
                throw domain_error("median of an empty vector");

        sort(first, last);

        int mid = sz/2;

        return sz % 2 == 0 ? (*(first+mid) + *(first+mid-1)) / 2 : *(first+mid);
}
