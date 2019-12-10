#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <climits>
#include <vector>

using namespace std;

// compute prefix sum of an array
// preconditions: arr has n elements; n > 0
const vector<int> prefix_sum(const vector<int> &arr) {
    vector<int> ps(1, arr[0]);
    for ( int i = 1, n = arr.size(); i < n; i++ )
        ps.push_back(ps.back() + arr[i]);
    return ps;
}

// calculate sum( arr[from + 1], ... , arr[to] ) given its prefix sum array
//     prefix_sum, where prefix_sum[i] = sum ( arr[0], ... , arr[i] )
// preconditions: to < prefix_sum.size()
int subarray_sum(const vector<int> &prefix_sum, const int to, const int from = -1) {
    if ( to < 0 || to <= from )
        return 0;
    return from > -1 ? prefix_sum[to] - prefix_sum[from] : prefix_sum[to];
}

// solve painter's partition problem using binary search with DP
// complexity: (time, space) = (O(k n log n), O(n))
// preconditions: *prefix_sum has n elements; n > 0; k > 0
int partition_dp(const vector<int> &prefix_sum, const int k) {
    
    // create dp tables
    const int n = prefix_sum.size();
    vector<int> dp_old(n+1, 0);
    vector<int> dp_new(n+1, 0);

    // initialize the tables for base case: k = 1
    for ( int i = 0; i < n; i++ )
        dp_old[i+1] = subarray_sum(prefix_sum, i, -1);

    // solve bottom-up
    for ( int p = 2; p <= k; p++ ) {
        
        for ( int j = p-1; j <= n; j++ ) {

            // best split between the time requirements
            int result = INT_MAX;

            // binary search for the best m (0 <= m <= j-1)
            int left = 0, right = j;
            while ( left < right ) {
                
                int m = (left+right) / 2;
                
                // time required from p-th worker
                int pth_time = subarray_sum(prefix_sum, j-1, m-1);

                // time required by p-1 workers
                int rest_time = dp_old[m];
                
                // update the best split found till now
                result = min(result, max(pth_time, rest_time));

                if ( pth_time < rest_time )
                    right = m;
                else if ( pth_time > rest_time )
                    left = m+1;
                else
                    break;
            }

            // record the best split
            dp_new[j] = result;
        }

        dp_old.swap(dp_new);
    }

    return dp_old.back();
}

// solve painter's partition problem using binary search
// complexity: (time, space) = (O(n log n), O(1))
// preconditions: *prefix_sum has n elements; n > 0; k > 0
int partition_bs(const vector<int> &prefix_sum, const int k) {
    return 0;
}

// brute-force solution - ref: geeksforgeeks.org/painters-partition-problem
// preconditions: *prefix_sum has n elements; n > 0; k > 0
int partition_bf(const vector<int> &prefix_sum, const int n, const int k) {
    // base cases
    if ( k == 1 )
        return subarray_sum(prefix_sum, n-1);
    if ( n == 1 )
        return prefix_sum[0];
    
    // try all partitions
    int best = INT_MAX;
    for ( int i = 1; i <= n; ++i )
        best = min(best, max(partition_bf(prefix_sum, i, k-1), subarray_sum(prefix_sum, n-1, i-1)));
    
    return best;
}

// test cases
TEST_CASE( "Base and corner cases", "[painter's partitions]" ) {
    
    int n, k;
    
    vector<int> A({ 1 });
    n = 1, k = 1;
    REQUIRE( partition_dp(A, k) == partition_bf(A, n, k) );
    REQUIRE( partition_bs(A, k) == partition_bf(A, n, k) );
    k = 2;
    REQUIRE( partition_dp(A, k) == partition_bf(A, n, k) );
    REQUIRE( partition_bs(A, k) == partition_bf(A, n, k) );
    k = 10;
    REQUIRE( partition_dp(A, k) == partition_bf(A, n, k) );
    REQUIRE( partition_bs(A, k) == partition_bf(A, n, k) );

    vector<int> B = prefix_sum({ 10, 20, 10, 40 });
    n = 4, k = 1;
    REQUIRE( partition_dp(B, k) == partition_bf(B, n, k) );
    REQUIRE( partition_bs(B, k) == partition_bf(B, n, k) );

    vector<int> C = prefix_sum({ 100, 1000, 1, 3, 22, 10101, 1 });
    n = 7, k = 1;
    REQUIRE( partition_dp(C, k) == partition_bf(C, n, k) );
    REQUIRE( partition_bs(C, k) == partition_bf(C, n, k) );
}

TEST_CASE( "Mid-sized cases", "[painter's partition]" ) {
    
    int n, k;
    
    vector<int> A = prefix_sum({ 10, 20, 30, 40 });
    n = 4, k = 2;
    REQUIRE( partition_dp(A, k) == partition_bf(A, n, k) );
    REQUIRE( partition_bs(A, k) == partition_bf(A, n, k) );
    k = 3;
    REQUIRE( partition_dp(A, k) == partition_bf(A, n, k) );
    REQUIRE( partition_bs(A, k) == partition_bf(A, n, k) );
    k = 4;
    REQUIRE( partition_dp(A, k) == partition_bf(A, n, k) );
    REQUIRE( partition_bs(A, k) == partition_bf(A, n, k) );
    k = 5;
    REQUIRE( partition_dp(A, k) == partition_bf(A, n, k) );
    REQUIRE( partition_bs(A, k) == partition_bf(A, n, k) );
    k = 10;
    REQUIRE( partition_dp(A, k) == partition_bf(A, n, k) );
    REQUIRE( partition_bs(A, k) == partition_bf(A, n, k) );

    vector<int> B = prefix_sum({ 10, 10, 10, 10, 10 });
    n = 5, k = 2;
    REQUIRE( partition_dp(B, k) == partition_bf(B, n, k) );
    REQUIRE( partition_bs(B, k) == partition_bf(B, n, k) );
    k = 3;
    REQUIRE( partition_dp(B, k) == partition_bf(B, n, k) );
    REQUIRE( partition_bs(B, k) == partition_bf(B, n, k) );
    k = 4;
    REQUIRE( partition_dp(B, k) == partition_bf(B, n, k) );
    REQUIRE( partition_bs(B, k) == partition_bf(B, n, k) );
    k = 5;
    REQUIRE( partition_dp(B, k) == partition_bf(B, n, k) );
    REQUIRE( partition_bs(B, k) == partition_bf(B, n, k) );
    k = 6;
    REQUIRE( partition_dp(B, k) == partition_bf(B, n, k) );
    REQUIRE( partition_bs(B, k) == partition_bf(B, n, k) );
    k = 7;
    REQUIRE( partition_dp(B, k) == partition_bf(B, n, k) );
    REQUIRE( partition_bs(B, k) == partition_bf(B, n, k) );
    k = 10;
    REQUIRE( partition_dp(B, k) == partition_bf(B, n, k) );
    REQUIRE( partition_bs(B, k) == partition_bf(B, n, k) );

    vector<int> C = prefix_sum({ 10, 20, 60, 50, 30, 40 });
    n = 6, k = 2;
    REQUIRE( partition_dp(C, k) == partition_bf(C, n, k) );
    REQUIRE( partition_bs(C, k) == partition_bf(C, n, k) );
    k = 3;
    REQUIRE( partition_dp(C, k) == partition_bf(C, n, k) );
    REQUIRE( partition_bs(C, k) == partition_bf(C, n, k) );
    k = 4;
    REQUIRE( partition_dp(C, k) == partition_bf(C, n, k) );
    REQUIRE( partition_bs(C, k) == partition_bf(C, n, k) );
    k = 5;
    REQUIRE( partition_dp(C, k) == partition_bf(C, n, k) );
    REQUIRE( partition_bs(C, k) == partition_bf(C, n, k) );
    k = 6;
    REQUIRE( partition_dp(C, k) == partition_bf(C, n, k) );
    REQUIRE( partition_bs(C, k) == partition_bf(C, n, k) );
    k = 7;
    REQUIRE( partition_dp(C, k) == partition_bf(C, n, k) );
    REQUIRE( partition_bs(C, k) == partition_bf(C, n, k) );
    k = 15;
    REQUIRE( partition_dp(C, k) == partition_bf(C, n, k) );
    REQUIRE( partition_bs(C, k) == partition_bf(C, n, k) );

    vector<int> D = prefix_sum({ 100, 200, 300, 400, 500, 600, 700, 800, 900 });
    n = 9, k = 2;
    REQUIRE( partition_dp(D, k) == partition_bf(D, n, k) );
    REQUIRE( partition_bs(D, k) == partition_bf(D, n, k) );
    k = 3;
    REQUIRE( partition_dp(D, k) == partition_bf(D, n, k) );
    REQUIRE( partition_bs(D, k) == partition_bf(D, n, k) );
    k = 4;
    REQUIRE( partition_dp(D, k) == partition_bf(D, n, k) );
    REQUIRE( partition_bs(D, k) == partition_bf(D, n, k) );
    k = 5;
    REQUIRE( partition_dp(D, k) == partition_bf(D, n, k) );
    REQUIRE( partition_bs(D, k) == partition_bf(D, n, k) );
    k = 6;
    REQUIRE( partition_dp(D, k) == partition_bf(D, n, k) );
    REQUIRE( partition_bs(D, k) == partition_bf(D, n, k) );
}
