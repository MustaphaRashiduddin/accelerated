#include <iostream>
#include <vector>
#include <algorithm>
#include <ostream>

using std::cout;
using std::vector;
using std::copy;
using std::ostream_iterator;

int main(int argc, char **argv)
{
        
        vector<int> v;
        for (int i=0; i<10; i++)
                v.push_back(i);
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
        return 0;
}
