#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

void query(const string& t) {
  cout << "? " << t << "\n"; cout.flush();
}

void answer(const string& t) {
  cout << "! " << t << "\n"; cout.flush();
}

bool read(int& res) { // check for -1 input
  cin >> res;
  if (res == -1) return false;
  return true;
}

bool solve() {
  int n;
  cin >> n;
  
  int res;
  if (n == 1) {
    query("0"); // check for it's "0"
    if (!read(res)) return false;
    if (res) answer(string(n, '0'));
    else answer(string(n, '1'));
  } else {
    query("0");
    if (!read(res)) return false;
    if (!res) {
      answer(string(n, '1')); // s doesn't contain any 0
      return true;
    }
    // s contains 0
    bool right = true;
    string curr("0");
    while (right && curr.size() < n) {
      query(curr.append("0"));
      if (!read(res)) return false;
      if (res) continue;

      curr[curr.size() - 1] = '1';

      query(curr);
      if (!read(res)) return false;
      if (res) continue;
      
      curr.pop_back();
      right = false;
    }

    // reached the right end of s, look left
    while (curr.size() < n) {
      query(curr.insert(0, "0"));
      if (!read(res)) return false;
      if (res) continue;

      curr[0] = '1';
      if (curr.size() == n) {
        break;
      }

      // query(curr); 
      // if (!read(res)) return false;
      // if (res) continue;

      // curr.erase(0, 1);
    }

    answer(curr);
  }
  return true;
}

int main() {
  // cin.sync_with_stdio(false);
  // cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    if (!solve()) return 0;
  }
}
