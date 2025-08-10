class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(nums);
        sort(a.begin(), a.end());
        if (a == nums)  return 0;
        
        vector<int> notSorted;
        for (int i = 0; i < n; i++) {
            if (nums[i] != a[i]) notSorted.push_back(nums[i]);
        }
        int maxV = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; (1 << i) <= maxV; i++) {
            bool ok = true;
            for (auto x : notSorted) {
                if (!(x & (1 << i))) ok = false;
            } 
            if (ok) ans += (1 << i); 
        } 
        return ans;
    }
};
