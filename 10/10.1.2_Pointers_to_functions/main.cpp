#include <iostream>

using std::cout;
using std::endl;

template<class In, class Pred>
In find_if(In begin, In end, Pred f);

bool is_negative(int n);

int main(int argc, char *argv[])
{
        int arr[] = {3, 6, 7};

        // bounds of range
        int *pBegin = arr;
        int *pEnd   = arr + sizeof(arr) / sizeof(arr[0]);

        int *pAns = find_if(pBegin, pEnd, is_negative);
        pEnd > pAns ? cout << *pAns << endl : cout << "not found" << endl;
}

template<class In, class Pred>
In find_if(In begin, In end, Pred f)
{
        while (begin != end && !f(*begin))
                ++begin;
        return begin;
}

bool is_negative(int n)
{
        return n < 0;
}
