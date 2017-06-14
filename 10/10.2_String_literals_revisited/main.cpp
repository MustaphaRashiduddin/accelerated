#include <iostream>

using std::cout;
using std::endl;

size_t strlen(const char *p);

int main(int argc, char *argv[])
{
        const char *str = "lolipop";
        cout << strlen(str) << endl;
        return 0;
}

size_t strlen(const char *p)
{
        size_t size = 0;
        while (*p++ != '\0')
                ++size;
        return size;
}
