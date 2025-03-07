#include <bits/stdc++.h>

using namespace std;

/**
 * LC2749: Min Operations to Make the Integer Zero
 * 
 * If the no. of operations is k, then the number of 1 bits in (num1 - k * num2) should be <= k <= target
 * 
 * Any positive integer X can be represented using a minimum of bitcount(X) bits, and maximum of X bits. 
 * 
 * Because any larger powers of 2 in X can be split into smaller powers: X = 2^0 * X (i.e. use X 1's to sum up to X)
 */
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long k=1;k<61;k++)
        {
            long long target=(long long)num1-k*(long long)num2;
            if (target>=0 && bitset<64>(target).count() <= k && k <= target)
            {
                return (int) k;
            }
        }
        return -1;
    }
};
