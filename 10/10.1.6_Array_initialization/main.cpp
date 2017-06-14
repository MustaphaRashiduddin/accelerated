#include<iostream>

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
        const int month_lengths[] = {
                31, 28, 31, 30, 31, 30,
                31, 31, 31, 31, 30, 31
        };
        const size_t n = sizeof(month_lengths) / sizeof(month_lengths[0]);
        for (int i=0; i<n; i++)
                cout << month_lengths[i] << " ";
        cout << endl;
        return 0;
}
