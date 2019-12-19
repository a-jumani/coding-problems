#include <climits>
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
    vector<vector<int> > memo(coins.size(), vector<int>(amount + 1, INT_MAX));
    for ( int i = 0; i < coins.size(); ++i )
        memo[i][0] = 0;
    
    for ( int i = 1; i <= amount; i++ ) {
        
        for ( int c = 0; c < coins.size(); ++c ) {

            // don't use coins[c]
            if ( c > 0 )
                memo[c][i] = memo[c-1][i];
            
            // use coins[c]
            if ( i-coins[c] >= 0 && memo[c][i-coins[c]] < INT_MAX )
                memo[c][i] = min(memo[c][i], 1 + memo[c][i-coins[c]]);
        }
    }

    int result = memo.back().back();
    return ( result == INT_MAX ) ? -1 : result;
}
