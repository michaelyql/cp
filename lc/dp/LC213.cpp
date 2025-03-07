class Solution {
  public:
      int rob(vector<int>& nums) {
          int n = nums.size();
          if (n == 1) return nums[0];
          return max(f(0, n - 2, nums), f(1, n - 1, nums));
      }
      int f(int l, int r, vector<int>& nums) {
          int a = 0, b = 0;
          for (int i = l; i <= r; i++) {
              int temp = max(a, nums[i] + b);
              b = a;
              a = temp;
          }
          return max(a, b);
      }
  };
