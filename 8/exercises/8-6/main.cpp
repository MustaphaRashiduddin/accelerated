#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::back_inserter;
using std::vector;
using std::pair;
using std::copy;

int main(int argc, char *argv[])
{
        map<int, string> m;
        vector<pair<int, string> > x;
        m.insert(pair<int, string>(1, "helo"));
        m.insert(pair<int, string>(2, "bombs away"));
        m.insert(pair<int, string>(3, "hola"));

        copy(m.begin(), m.end(), back_inserter(x));

        for (vector<pair<int, string> >::const_iterator iter=x.begin(); iter!=x.end(); iter++)
                cout << iter->first << " " << iter->second << endl;

        return 0;
}
