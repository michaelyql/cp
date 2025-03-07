#include <bits/stdc++.h>
#include "helpers.cpp"
using namespace std;

using ll = long long;
using pii = pair<int, int>;

// custom pair hashing
struct pair_hash {
  size_t operator()(const pair<pii, int> &p) const {
    return (p.first.first << 16) ^ p.first.second;
  }
};

// template specialization for pair<pii, int> 
template <> 
struct equal_to<pair<pii, int>> {
  bool operator()(const pair<pii, int> &p1, const pair<pii, int> &p2) const {
    return p1.first == p2.first;
  }
};

int main() {
  cin.sync_with_stdio(false);
  unordered_set<pair<pii, int>, pair_hash> s;
  s.insert({{1, 2}, 1});
  s.insert({{2, 3}, 2});
  s.insert({{3, 4}, 3});
  auto it = s.find({{1, 2}, 0}); // found
  // s.find({{1, 2}, 0}); // found as well
  if (it != s.end()) {
    cout << "Found" << endl;
    cout << *it << endl;
  } else {
    cout << "Not found";
  }
}
