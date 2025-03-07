#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll k, vector<ll> &v) {
  int n=v.size();
  if (n % 2 == 0) { // n is even
    for (int i=0;i<n-1;i += 2) {
      if (v[i+1]-v[i]>k) return false;
    }
    return true;
  } else { // n is odd
    int jumps = 0;
    for (int i=0;i<n-1;){
      if (v[i+1]-v[i]<=k) {
        i += 2;
        continue;
      }
      else {
        if (jumps == 1) return false;
        jumps++;
        i += 1;
      }
    }
    return true;
  }
}

void solve(){
  int n;cin>>n;
  vector<ll> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  ll left = 1;
  ll right = v[n-1] - v[0] + 1;
  while (left < right) {
    ll k = left + (right-left)/2;
    if (check(k, v)) right = k;
    else left = k + 1;
  }
  cout<<left<<endl;
}

int main() {
  int t;cin>>t;
  while (t--) solve();
}
