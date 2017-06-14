#include <iostream>

using std::cout;
using std::endl;

template <class T> void swap(T& a, T& b);

int main(int argc, char** argv)
{
        int x=3;
        int y=4;
        swap(x,y);
        cout << x << " " << y << endl;
        return 0;
}

template <class T> void swap(T& a, T& b)
{
        T c(a); a=b; b=c;
}
