#include <iostream>
#include <vector>

using std::cout;
using std::endl;

template<class T>
void swap(T& e1, T& e2)
{
        T tmp = e1;
        e1 = e2;
        e2 = tmp;
}

template<class Bi>
void reverse(Bi begin, Bi end)
{
        while (begin != end) {
                --end;
                if (begin != end)
                        swap(*begin++, *end);
        }
}

int main(int argc, char *argv[])
{
        int myints[] = {21, 22, 23, 24, 25};
        size_t sz = sizeof(myints)/sizeof(*myints);
        reverse(myints, myints+sz);
        for (int i=0; i<sz; i++)
                cout << ' ' << myints[i];
        cout << endl;
        return 0;
}
