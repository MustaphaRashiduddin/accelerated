#include <istream>
#include <iostream>
#include <vector>

using std::istream_iterator;
using std::cin;
using std::vector;
using std::back_inserter;
using std::copy;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
        vector<int> v;
        copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));

        for (vector<int>::const_iterator iter=v.begin(); iter!=v.end(); iter++)
                cout << *iter << endl;

        return 0;
}
