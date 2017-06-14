#include "String_list.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::list;
using std::string;

string* copystuff(string* p_str, string str, size_t& n);

void String_list::push(string str)
{
        if (p_str == 0) {
                p_str = new string;
                *p_str = str;
                ++n;
        } else {
                p_str = copystuff(p_str, str, n);
        }
}

string* copystuff(string* p_str, string str, size_t& n)
{
        string *p_temp = p_str;
        p_str = new string[n+1];


        for (size_t i=0; i<n; ++i)
                p_str[i] = p_temp[i];

        p_str[n] = str;

        if (n++ == 1)
                delete p_temp;
        else
                delete[] p_temp;

        return p_str;
}

String_list::~String_list()
{
        if (n == 1) 
                delete p_str;
        else if (n > 1)
                delete[] p_str;
}
