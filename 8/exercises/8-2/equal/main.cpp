#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename inputIterator1, typename inputIterator2>
bool equall(inputIterator1 first1, inputIterator1 last1, inputIterator2 first2);

int main(int argc, char *argv[])
{
        int myints[] = {20, 40, 60, 40, 20};
        vector<int> myvector(myints, myints+5);
        if (equall(myints, myints+5, myvector.rbegin())) {
                cout << "palindrome";
        } else {
                cout << "not palindrome";
        }
        cout << endl;

        return 0;
}

template <typename inputIterator1, typename inputIterator2>
bool equall(inputIterator1 first1, inputIterator1 last1, inputIterator2 first2)
{
        while (first1 != last1)
                if (*first1++ != *first2++)
                        return false;
        return true;
}
