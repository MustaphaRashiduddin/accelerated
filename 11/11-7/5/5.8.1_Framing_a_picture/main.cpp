#include <iostream>
#include <vector>
#include "./../../vec.hpp"

using std::vector;
using std::string;
using std::max;
using std::cout;
using std::endl;

string::size_type width(const Vec<string>&);
Vec<string> frame(const Vec<string>& v);

int main(int argc, char *argv[])
{
        Vec<string> v_str;
        v_str.push_back("saif");
        v_str.push_back("ali");
        v_str.push_back("mahdi");
        v_str.push_back("pew pew boom splat");

        Vec<string> v_str_pretty = frame(v_str);

        for (Vec<string>::const_iterator iter=v_str_pretty.begin(); iter!=v_str_pretty.end(); iter++)
                cout << *iter << endl;

        return 0;
}

string::size_type width(const Vec<string>& v)
{
        string::size_type maxlen = 0;
        for (Vec<string>::size_type i=0; i!=v.size(); ++i)
                maxlen = max(maxlen, v[i].size());
        return maxlen;
}

Vec<string> frame(const Vec<string>& v)
{
        Vec<string> ret;
        string::size_type maxlen = width(v);
        string border(maxlen + 4, '*');

        // write the top border
        ret.push_back(border);

        // write each interior row, bordered by an asterisk and a space
        for (Vec<string>::size_type i=0; i!=v.size(); ++i)
                ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ')+ " *");

        // write the bottom border
        ret.push_back(border);
        return ret;
}
