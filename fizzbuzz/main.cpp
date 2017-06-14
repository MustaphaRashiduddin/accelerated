#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
        for (int i=1; i<=100; i++) {
                if (i%5==0 || i%3==0) {
                        if (i%3==0) cout << "Fizz";
                        if (i%5==0) cout << "Buzz";
                        cout << endl;
                } else {
                        cout << i << endl;
                }
        }
        return 0;
}
