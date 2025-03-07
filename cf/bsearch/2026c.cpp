#include <bits/stdc++.h>
using namespace std;

bool check(int k, string &s, int n) {
  
}

void solve() {
  int n; 
  string s;
  cin>>n;
  cin>>s;
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  int ones_cnt = 0;
  for (int i=0;i<n;i++) if (s[i]=='1') ones_cnt++;
  int l=1;
  int r=ones_cnt;
  
  // binary search over min number of days needed
  while (l<r) {
    int mid=l+(r-l)/2;
    if (check(mid, s, n)) r = mid;
    else l = mid + 1;
  }
  
  int cost = 0;
  // take the days starting from the back
  for (int i=n-1;i>=0;i--){
    if (s[i]=='1') {
      if (l > 0) l--;
      else {
        cost += i+1;
      }
    }
    else {
      cost += i+1;
    }
  }
  cout << cost;
}

int main() {
  int t;cin>>t;
  while (t--) solve();
}
