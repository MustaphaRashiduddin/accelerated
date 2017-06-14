#include "stdio.h"
#include "string.h"
#include "Vec.hpp"

int main(int argc, char *argv[])
{
        const char* something = "lol";
        printf("%s\n", something);
        Vec<int> g;
        Vec<int> v(100);
        return 0;
}
