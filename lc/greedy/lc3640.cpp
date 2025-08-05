#include <bits/stdc++.h>

using ll = long long;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        const ll NOT_SET = -1e15;
        vector<ll> s1(n, NOT_SET), s2(n, NOT_SET), s3(n, NOT_SET);
        long long ans = -1e15; 
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                if (s1[i + 1] != NOT_SET) {
                    s1[i] = nums[i] + max(s1[i + 1], 1ll * nums[i + 1]);
                } else {
                    s1[i] = nums[i] + nums[i + 1];
                }
                if (s2[i + 1] != NOT_SET) {
                    s3[i] = nums[i] + s2[i + 1]; 
                    ans = max(ans, s3[i]);
                } 
                if (s3[i + 1] != NOT_SET) {
                    s3[i] = nums[i] + s3[i + 1];
                    ans = max(ans, s3[i]);
                }
            }
            if (nums[i] > nums[i + 1]) {
                if (s1[i + 1] != NOT_SET) s2[i] = nums[i] + s1[i + 1];
                if (s2[i + 1] != NOT_SET) s2[i] = nums[i] + s2[i + 1];
            }
        } 
        return ans;
    }
};
