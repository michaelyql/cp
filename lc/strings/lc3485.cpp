struct TrieNode {
  TrieNode* children[26];
  unordered_map<int, int> freq;
  TrieNode() {
      for (int i = 0; i < 26; i++) {
          children[i] = nullptr;
          freq[i] = 0;
      }
  }
  int best = 0, second_best = 0;
  int best_idx = -1, second_best_idx = -1;
};

class Solution {
  void f(TrieNode* curr, int k) {
      for (int i = 0; i < 26; i++) {
          if (curr->freq[i] >= k) {
              f(curr->children[i], k);

              int candidate = 1 + curr->children[i]->best;

              if (curr->best_idx == -1) {
                  curr->best_idx = i;
                  curr->best = candidate;
                  continue;
              }

              if (candidate >= curr->best) {
                  curr->second_best_idx = curr->best_idx;
                  curr->second_best = curr->best;
                  curr->best_idx = i;
                  curr->best = candidate;
                  continue;
              } 

              if (curr->second_best_idx == -1) {
                  curr->second_best_idx = i;
                  curr->second_best = candidate;
                  continue;
              } 

              if (candidate > curr->second_best) {
                  curr->second_best_idx = i;
                  curr->second_best = candidate;
              }
          }
      }
  }
  int check(TrieNode* curr, string& word, int idx, int k) {
      if (curr->best_idx == -1) {
          return 0;
      }
      int cand_idx = word[idx] - 'a';
      if (curr->best_idx != cand_idx) {
          return curr->best;
      }
      
      if (curr->freq[curr->best_idx] - 1 < k) {
          if (curr->second_best_idx == -1) {
              return 0;
          } else {
              return curr->second_best;
          }
      } else {
          if (curr->second_best == curr->best) {
              return curr->second_best;
          }
          return max(
              curr->second_best, 
              1 + check(curr->children[cand_idx], word, idx + 1, k));
      }
          
  }
public:
  vector<int> longestCommonPrefix(vector<string>& words, int k) {
      int n = words.size();
      if (n - 1 < k) {
          return vector<int>(n, 0);
      } 
      TrieNode root;
      TrieNode* curr;
      curr = &root;
      
      for (string& word : words) {
          curr = &root;
          for (char c : word) {
              int idx = c - 'a';
              if (curr->children[idx] == nullptr) {
                  curr->children[idx] = new TrieNode(); 
              } 
              curr->freq[idx]++;
              curr = curr->children[idx]; 
          }
      }
      f(&root, k);

      vector<int> ans(n);
      for (int i = 0; i < n; i++) {
          ans[i] = check(&root, words[i], 0, k);
      }
      return ans;
  }
};
