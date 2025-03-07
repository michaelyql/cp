#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n,k;cin>>n>>k;
  string s;cin>>s;
  vector<int> suffix(n,0);
  suffix[n-1] = (s[n-1]=='0') ? -1 : 1;
  for (int i=n-2;i>0;i--){
    if(s[i]=='0') suffix[i] = suffix[i+1] - 1;
    else suffix[i] = suffix[i+1] + 1;
  }
  sort(suffix.begin(),suffix.end());
  reverse(suffix.begin(),suffix.end());
  int i=0;
  int sum=0;
  while (k>0 && i < n && suffix[i] > 0) {
    k -= suffix[i++];
  }
  if (sum < k) cout << -1 << endl;
  else cout << i+1 << endl;
}

int main() {
  int t;cin>>t;
  while(t--)solve();
}
