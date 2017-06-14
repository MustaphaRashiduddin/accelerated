#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::search;

/*
 * Searches for the first occurance of the subsequence of elements [s_first, s_last)
 * in the range [first, last - (s_last - s_first))
 */
template <typename ForwardIt1, typename ForwardIt2>
ForwardIt1 searchh(ForwardIt1, ForwardIt1, ForwardIt2, ForwardIt2);

int main(int argc, char *argv[])
{
        string str1 = "didilbo";
        string str2 = "id";
        string::iterator i; 
        if ((i = searchh(str1.begin(), str1.end(), str2.begin(), str2.end())) != str1.end())
                cout << *i << endl;
        else
                cout << "not found" << endl;
        return 0;
}

/*
 * Searches for the first occurance of the subsequence of elements [s_first, s_last)
 * in the range [first, last - (s_last - s_first))
 */
template <typename ForwardIt1, typename ForwardIt2>
ForwardIt1 searchh(ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last)
{
        int i=0;
        ForwardIt2 t_s_first = s_first;
        do {
                if (*t_s_first != *first)
                        t_s_first = s_first;
                if (*t_s_first == *first) {
                        ++t_s_first;
                        ++i;
                }
        } while (first++ != last && t_s_first != s_last);

        if (t_s_first == s_last)
                return first-i;
        else
                return last;
}
