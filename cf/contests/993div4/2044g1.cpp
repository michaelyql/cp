#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> b(n, 0);
  for (int i = 0; i < n; i++) {
    int x; 
    cin >> x;
    x--;
    b[x]++;
    b[i]--;
  }
  unordered_set<string> states;
  string curr_state(n, '1');
  int year = 1;
  while (states.find(curr_state) == states.end()) {
    states.insert(curr_state);
    year++;
    for (int i = 0; i < n; i++) {
      
    }
  }
  cout << year << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
