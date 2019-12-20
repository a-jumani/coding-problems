#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// minimum number of coins needed for change of given
// amount; -1 if change is not possible
//
// eq: S(i, c) = min{S(i, c-1), S(i-coins[c], c), where
// S(i, c) is the minimum number of coins needed for
// change of amount i using only coins[:c+1]
// 
// preconditions:
//   coins[i] >= 0
//   amount >= 0
int coin_change(const vector<int>& coins, const int amount) {

    // initialize memo for amount 0
    vector<int> memo(amount + 1, INT_MAX);
    memo[0] = 0;
    
    for ( int i = 1; i <= amount; i++ )
        for ( auto c : coins )
            if ( i-c >= 0 && memo[i-c] < memo[i] )
                memo[i] = 1 + memo[i-c];

    return ( memo.back() == INT_MAX ) ? -1 : memo.back();
}
