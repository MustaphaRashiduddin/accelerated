#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char *argv[])
{
        int x = 5;
        
        int *p = &x;
        cout << "x " << x << endl;

        *p = 6;
        cout << "x " << x << endl;

        return 0;
}
