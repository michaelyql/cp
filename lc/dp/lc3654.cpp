class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size(); 
        map<int, long long> mp;
        mp[0] = 0;
        long long csum = 0;
        for (int i = 0; i < n; i++) {
            csum += nums[i];
            if (mp.find(csum % k) != mp.end()) {
                // since csum = mp[csum % k], we want mp[csum % k] to be as small as possible
                mp[csum % k] = min(mp[csum % k], csum);

                // csum = csum - (csum - mp[csum % k]);
                csum = mp[csum % k];
            } else {
                mp[csum % k] = csum;
            }
        }
        return csum;
    }
};
