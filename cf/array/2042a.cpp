#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n,k;cin>>n>>k;
  vector<int> v;
  for (int i=0;i<n;i++) {
    int x;cin>>x;
    v.push_back(x);
  }
  sort(v.begin(),v.end());
  for (int i=n-1;i>=0;i--) {
    if (k==0) break;
    if (v[i]<=k) k -= v[i];
    else break;
  }
  cout << k << endl;
}

int main() {
  int t;cin>>t;
  while(t--) solve();
}
