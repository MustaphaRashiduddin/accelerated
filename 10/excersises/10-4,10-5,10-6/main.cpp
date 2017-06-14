#include <iostream>
#include <list>
#include "String_list.hpp"
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

bool space(char c);
bool not_space(char c);
void split(String_list* s_l, const string& str);

int main(int argc, char *argv[])
{
        String_list s_l;
        split(&s_l, "hello world of pong");

        for (string* it=s_l.begin(); it!=s_l.end(); ++it)
                cout << *it << endl;

        return 0;
}

void split(String_list* s_l, const string& str)
{
        typedef string::const_iterator iter;
        vector<string> ret;

        iter i = str.begin();
        while (i != str.end()) {

                // ignore leading blanks
                i = find_if(i, str.end(), not_space);

                // find end of next word
                iter j = find_if(i, str.end(), space);

                // copy the characters i [i, j)
                if (i != str.end())
                        s_l->push(string(i, j));
                i = j;
        }
}

bool space(char c)
{
        return isspace(c);
}

bool not_space(char c)
{
        return !isspace(c);
}
