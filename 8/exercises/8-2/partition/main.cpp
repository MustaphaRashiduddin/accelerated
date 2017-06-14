#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::partition;
using std::back_inserter;
using std::swap;
using std::stable_partition;

template <typename BidirectionalIterator, typename UnaryPredicate>
BidirectionalIterator partitionn(BidirectionalIterator, BidirectionalIterator, UnaryPredicate);

bool isOdd(int i) {return i % 2 == 1;}

int main(int argc, char *argv[])
{
        vector<int> myvector;

        // set some vals
        for (int i=1; i<10; i++)
                myvector.push_back(i);

        vector<int>::iterator bound;
        bound = partitionn(myvector.begin(), myvector.end(), isOdd);

        // print out content
        cout << "odd elements:";
        for (vector<int>::iterator it=myvector.begin(); it!=bound; ++it)
                cout << ' ' << *it;
        cout << endl;

        cout << "even elements:";
        for (vector<int>::iterator it=bound; it!=myvector.end(); ++it)
                cout << ' ' <<  *it;
        cout << endl;

        return 0;
}

template <typename BidirectionalIterator, typename UnaryPredicate>
BidirectionalIterator partitionn(BidirectionalIterator first, BidirectionalIterator last, UnaryPredicate pred)
{
        while (first != last) {
                while (pred(*first)) {
                        ++first;
                        if (first == last) return first;
                }
                do {
                        --last;
                        if (first == last) return first;
                } while (!pred(*last));
                swap(*first, *last);
                ++first;
        }
        return first;
}
