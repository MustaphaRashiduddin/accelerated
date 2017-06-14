#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::copy;
using std::back_inserter;

int main(int argc, char *argv[])
{
        const size_t NDim = 3;
        int coords[NDim] = {3, 6, 1};
        vector<double> v;
        copy(coords, coords+NDim, back_inserter(v));

        for (vector<double>::const_iterator it=v.begin(); it!=v.end(); it++)
                cout << *it << " ";
        cout << endl;

        return 0;
}
