#include "prog.hpp"
#include <time.h>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ostream_iterator;

int main(int argc, char *argv[])
{
        srand(time(NULL));
        // generate the sentence        
        // vector<string> sentence = gen_sentence(read_grammar(cin));

        // test code
        Grammar ret;
        ret["<noun>"].push_back(Rule(split("cat")));
        ret["<noun>"].push_back(Rule(split("dog")));
        ret["<noun>"].push_back(Rule(split("table")));
        ret["<noun-phrase>"].push_back(Rule(split("<noun>")));
        ret["<noun-phrase>"].push_back(Rule(split("<adjective> <noun-phrase>")));
        ret["<adjective>"].push_back(Rule(split("large")));
        ret["<adjective>"].push_back(Rule(split("brown")));
        ret["<adjective>"].push_back(Rule(split("absurd")));
        ret["<verb>"].push_back(Rule(split("jumps")));
        ret["<verb>"].push_back(Rule(split("sits")));
        ret["<location>"].push_back(Rule(split("on the stairs")));
        ret["<location>"].push_back(Rule(split("wherever it wants")));
        ret["<sentence>"].push_back(Rule(split("the <noun-phrase> <verb> <location>")));

        vector<string> sentence = gen_sentence(ret);
        // test code ends

        // write the first word, if any
        ostream_iterator<string> out_it(cout, " ");
        vector<string>::const_iterator it = sentence.begin();
        if (!sentence.empty()) {
                out_it = *it;
                ++it;
        }

        // write the rest of the words, each preceded by a space
        while (it != sentence.end()) {
                out_it = *it;
                ++it;
        }
        cout << endl;

        return 0;
}
