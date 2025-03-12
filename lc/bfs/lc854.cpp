class Solution {
  public:
      int kSimilarity(string s1, string s2) {
          unordered_set<string> seen;
          queue<string> q;
          int n = s1.size();
  
          seen.insert(s1);
          q.push(s1);
          int ans = 0;
  
          while (!q.empty()) {
              int sz = q.size();
              while (sz--) {
                  string next = q.front();
                  q.pop();
                  
                  if (next == s2) {
                      return ans;
                  }
                  int i = 0;
                  while (i < n && next[i] == s2[i]) i++;
                  for (int j = i + 1; j < n; j++) {
                      if (next[j] != s2[j] && next[j] == s2[i]) {
                          string temp = next;
  
                          temp[i] = next[j];
                          temp[j] = next[i];
  
                          if (seen.find(temp) == seen.end()) {
                              q.push(temp);
                              seen.insert(temp); 
                          }
                      }
                  }
              }
              ans += 1;
          }
          return ans;
      }
  };
