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
    vector<int> memo(C+1, 0);

    for ( int i = 0; i < v.size(); ++i )
        for ( int c = C; c >= 0; --c )
            if ( w[i] <= c )
                memo[c] = max(memo[c], memo[c-w[i]] + v[i]);

    return memo.back();
}
