class Solution {
  public:
      int minimizeXor(int num1, int num2) {
          int cnt = 0;
          for (int i = 0; i < 31; i++) {
              if ((1 << i) & num2) cnt++;
          }
          int i = 30;
          int ans = 0;
          while (cnt > 0 && i >= 0) {
              if ((1 << i) & num1) {
                  cnt--;
                  ans |= (1 << i);
              }
              i--;
          }
          i = 0;
          while (cnt > 0 && i <= 30) {
              if (!((1 << i) & num1)) {
                  cnt--;
                  ans |= (1 << i);
              }
              i++;
          }
          return ans;
      }
  };
