#include <bits/stdc++.h>
// #include "helpers.cpp"
using namespace std;

using pii = pair<int, int>;

void solve() {
  int n;cin>>n;
  vector<pii> users; // (l_i, r_i) for each user
  unordered_map<string, int> userMap; // map from user to their index 
  for (int i=0;i<n;i++){
    int l,r;
    cin>>l>>r;
    string user = to_string(l) + "#" + to_string(r);
    users.push_back({l, r}); // TODO: fix for duplicate ranges
    userMap.emplace(user, i);
  }
  // sort by left start point, break ties by right end point
  sort(users.begin(), users.end(), [](auto &a, auto &b) {
    return a.first != b.first ? a.first < b.first : a.second > b.second;
  });
  // cout << "Users sorted by left endpoint (ascending): " << users;
  set<int> S;
  vector<int> ans(n, 0);
  for (int i=0;i<n;i++) {
    pii user = users[i];
    int userIdx = userMap[to_string(user.first) + "#" + to_string(user.second)];
    int r = user.second;
    auto R = S.lower_bound(r);
    if (R != S.end()) ans[userIdx] += (*R) - r;
    S.insert(r);
  }
  // sort by right end point, break ties by left
  sort(users.begin(), users.end(), [](auto &a, auto &b) {
    return a.second != b.second ? a.second > b.second : a.first < b.first;
  });
  // cout << "Users sorted by right endpoint (descending): " << users;
  S.clear();
  for (int i=0;i<n;i++) {
    pii user = users[i];
    int userIdx = userMap[to_string(user.first) + "#" + to_string(user.second)];
    int l = user.first;
    auto L = S.upper_bound(l);
    if (L != S.begin()) {
      L--;
      ans[userIdx] += l - (*L);
    }
    S.insert(l);
  }
  for (auto &x: ans) cout << x << endl;
}

int main() {
  int t;cin>>t;
  while(t--)solve();
}
