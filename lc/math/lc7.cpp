class Solution {
  public:
      int reverse(int x) {
          bool neg = x & ((unsigned long) 1 << 31);
          vector<int> nums;
          while (x != 0) {
              nums.push_back(x % 10);
              x /= 10;
          }
          int res = 0;
          int p = 1;
  
          int n = nums.size();
          for (int i = n - 1; i >= 0; i--) {
              int v = nums[i];
              if (abs(v) > INT_MAX / p) return 0;
              if (neg) {
                  if (res < INT_MIN - v * p) return 0;
              } else {
                  if (res > INT_MAX - v * p) return 0;
              }
              res = res + v * p;
              if (p <= INT_MAX / 10) p *= 10;
          }
          return res;
          
      }
  };
