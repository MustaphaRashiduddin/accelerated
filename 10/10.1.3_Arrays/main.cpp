#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
        const size_t NDim = 3;
        double coords[NDim];
        *coords = 1.5;
        cout << coords[0] << endl;
        return 0;
}
