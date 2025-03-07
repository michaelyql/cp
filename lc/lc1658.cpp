#include <bits/stdc++.h>
using namespace std;

/**
 * LC1658: Minimum Operations to Reduce X to Zero
 * 
 * Transform the question into looking for the biggest subarray that sums exactly to sum(nums) - X
 */
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l = 0;
        int ans=10e7;
        int sum=0;
        int target=accumulate(nums.begin(),nums.end(),0)-x;
        int n=nums.size();
        for(int r=0;r<n;r++)
        {
            sum+=nums[r];
            if (sum==target)
                ans=min(ans,n-(r-l+1));
            while(sum>=target && l <= r)
            {
                sum-=nums[l++];
                if (sum==target)
                    ans=min(ans,n-(r-l+1));
            }
        }
        if (ans==10e7) return -1;
        return ans;
    }
};
