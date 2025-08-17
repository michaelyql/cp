class Solution {
    /*
     * finds the index of the peak nums[l..r]
     */
    int search(int l, int r, vector<int>& nums) {
        if (l == r) return l;
        if (nums[l] < nums[r]) return r; // already sorted
        int m = (l + r) / 2;
        int a = search(l, m, nums);
        int b = search(m + 1, r, nums);
        if (nums[a] > nums[b]) return a;
        else return b;
    }
    /**
     * search nums[l..r] for target 
     */
    int get_idx(int l, int r, vector<int>& nums, int target, int n) {
        if (l >= n || l > r) return -1;
        auto start = nums.begin() + l;
        auto end = nums.begin() + r + 1;
        auto it = lower_bound(start, end, target);
        if (it == end || *it != target) return -1;
        return it - start;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(); 
        int peak_idx = search(0, n - 1, nums);
        int a = get_idx(0, peak_idx, nums, target, n);
        int b = get_idx(peak_idx + 1, n - 1, nums, target, n);
        if (a != -1) return a;
        else if (b != -1) return b + peak_idx + 1;
        else return -1;
    }
};
