#include <bits/stdc++.h>
using namespace std;

/**
 * LC128: Longest Consecutive Sequence
 * 
 * No need to use complicated method like UFDS
 * Start of a sequence <=> num - 1 does not exist inside nums
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) s.insert(num);
        int ans=0;
        for (int num : nums)
        {
            if (s.find(num-1)==s.end())
            {
                int sz=1;
                while (s.find(num+1)!=s.end())
                {
                    sz++;
                    num++;
                }
                ans=max(ans,sz);
            }
        }
        return ans;
    }
};
