class Solution {
    
  public:
      string smallestSubsequence(string s, int k, char letter, int repetition) {
          int cnt = 0;
          int remove = s.size() - k;
          for (auto c : s) {
              if (c == letter) cnt++;
          }
          string stk;
          int extra = cnt - repetition; 
          for (auto c : s) {
              while (!stk.empty() && stk.back() > c && remove) {
                  if (stk.back() == letter) {
                      if (!extra) break;
                      extra--;
                  }
                  stk.pop_back();
                  remove--;
              }
              stk += c;
          }
          string res;
          int need = repetition;
          for (int i = 0; i < stk.size(); i++) {
              if (res.size() >= k) break;
              if (stk[i] == letter) {
                  if (res.size() >= k) continue;
                  need--;
                  res += stk[i];
              } else {
                  if (res.size() + need >= k) continue;
                  res += stk[i];
              }
          }
          return res;
      }
  };
  
  