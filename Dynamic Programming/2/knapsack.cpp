#include <vector>

using namespace std;

// max value of items that can be fit in capacity C
//
// eq: S(c, i) = max{v[i] + S(c-w[i], i-1), S(c, i-1)},
// where S(c, i) is the maximum value with capacity c
// items[:i+1].
//
// preconditions:
//   w[i] >= 0
//   C >= 0
int knapsack(const vector<int> &v, const vector<int> &w, int C) {
    // initialize memo for 0 items
    vector<int> memo_old(C+1, 0), memo_new(C+1, 0);

    for ( int i = 0; i < v.size(); ++i ) {
        for ( int c = 0; c <= C; ++c ) {

            // don't include item i
            memo_new[c] = memo_old[c];

            // include item i
            if ( w[i] <= c )
                memo_new[c] = max(memo_new[c], memo_old[c-w[i]] + v[i]);
        }

        swap(memo_old, memo_new);
    }

    return memo_old.back();
}
