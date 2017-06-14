#include <iostream>

using std::copy;
using std::cout;
using std::endl;

char* duplicate_chars(const char* p);

int main(int argc, char *argv[])
{
        const char *str = "looky here";        
        const char *str2 = duplicate_chars(str);

        cout << str2 << endl;

        delete str2;
        str2 = 0;
        
        return 0;
}

char* duplicate_chars(const char* p)
{
        // allocate enough space; remember to add one for the null
        size_t length = strlen(p) + 1;
        char* result = new char(length);

        // copy into our newly allocated and return pointer to first element
        copy(p, p+length, result);
        return result;
}
