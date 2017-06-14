#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::find_if;
using std::isspace;

bool space(const char&);

template <typename InputIterator, typename Predicate>
InputIterator findd_if(InputIterator, InputIterator, Predicate);

int main(int argc, char *argv[])
{
        string uncle = "bobs your uncle";
        string::iterator it = findd_if(uncle.begin(), uncle.end(), space);
        string::iterator lol = findd_if(it, uncle.end(), space);

        for (string::const_iterator iter=lol; iter!=uncle.end(); iter++)
                cout << *iter;
        cout << endl;
        
        return 0;
}

template <typename InputIterator, typename Predicate>
InputIterator findd_if(InputIterator first, InputIterator last, Predicate pred)
{
        while (first != last) {
                if (space(*first))
                        return first;
                ++first;
        }
        return last;
}

bool space(const char& c)
{
        return isspace(c); 
}
