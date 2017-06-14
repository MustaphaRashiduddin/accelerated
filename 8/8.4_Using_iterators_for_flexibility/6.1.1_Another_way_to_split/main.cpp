#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::find_if;
using std::cout;
using std::back_inserter;
using std::list;
using std::getline;
using std::ostream_iterator;

bool space(char);
bool not_space(char);
template<class Out>
void split(const string&, Out);

int main(int argc, char *argv[])
{
        /*
         * list<string> v; 
         * split("greetings people of the earth", back_inserter(v)); 
         * for (list<string>::const_iterator iter=v.begin(); iter!=v.end(); iter++)
         *         cout << *iter << endl;
         */
        string s;
        while (getline(cin, s))
                split(s, ostream_iterator<string>(cout, "\n"));
        return 0;
}

bool space(char c) { return isspace(c); } 
bool not_space(char c)
{
        return !isspace(c);
}

template<class Out>
void split(const string& str, Out os)
{
        typedef string::const_iterator iter;

        iter i = str.begin();
        while (i != str.end()) {

                // ignore leading blanks
                i = find_if(i, str.end(), not_space);

                // find end of next word
                iter j = find_if(i, str.end(), space);

                // copy the characters i [i, j)
                if (i != str.end())
                        *os++ = string(i, j);
                i = j;
        }
}
