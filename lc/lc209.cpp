#include <bits/stdc++.h>

using namespace std;

/**
 * LC209: Minimum Size Subarray Sum
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 10e7;
        int l=0,r=0;
        int sum=0;
        while(r<nums.size())
        {
            int cur=nums[r];
            sum+=cur;
            if(sum>=target)
            {
                ans=min(ans,r-l+1);
            }
            while(sum>=target)
            {
                sum -= nums[l++];
                if (sum>=target)
                    ans=min(ans,r-l+1);
            }
            r++;
        }
        if (ans==10e7)return 0;
        return ans;
    }
};
