#include <fstream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::string;
using std::ofstream;
using std::endl;

int main(int argc, char *argv[])
{
        ifstream infile("in");
        ofstream outfile("out");

        string s;

        while (getline(infile, s))
                outfile << s << endl;
        return 0;
}
