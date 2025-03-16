class Solution {
  public:
      string subStrHash(string s, int power, int modulo, int k, int hashValue) {
          int n = s.size();
          int sz = 0;
  
          long long cur_hash = 0;
          long long p = 1;
          int res = 0;
  
          for (int i = 0; i < k; i++) {
              p = p * power % modulo;
          }
  
          for (int i = n - 1; i >= 0; i--) {
              cur_hash = cur_hash * power % modulo;
              cur_hash = (cur_hash + s[i] - 'a' + 1) % modulo;
              if (sz < k) {           
                  sz++;
                  if (sz == k && cur_hash == hashValue) res = n - k;
              } else {
                  cur_hash = (cur_hash - (s[i + k] - 'a' + 1) * p % modulo + modulo) % modulo;
                  if (cur_hash == hashValue) res = i;
              }
          }   
          return s.substr(res, k);
      }
  };
  
  