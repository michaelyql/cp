class Solution {
  // 1. generate subsequences
  // 2. check if subsequence ok
public:
  string longestSubsequenceRepeatedK(string s, int k) {
      queue<string> q;
      q.push("");
      string res = "";
      while (!q.empty()) {
          string cur = q.front();
          q.pop();
          for (char c = 'a'; c <= 'z'; c++) {
              string next = cur + c;
              if (ok(s, next, k)) {
                  res = next;
                  q.push(next);
              }
          }
      }
      return res;
  }
  bool ok(string& s, string& p, int k) {
      int i = 0, j = 0, cnt = 0;
      while (i <= s.size()) {
          if (j == p.size()) {
              j = 0;
              cnt++;
          }
          if (i == s.size()) break;
          if (s[i] == p[j]) {
              j++;
          } 
          i++;
      }
      return cnt >= k;
  }
};


