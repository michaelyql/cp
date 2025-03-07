#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n,q;
  cin>>n>>q;
  string a;cin>>a;
  string b;cin>>b;
  vector<vector<int>> afreq(n+1, vector<int>(26, 0));
  vector<vector<int>> bfreq(n+1, vector<int>(26, 0));
  for (int i=1;i<=n;i++){
    afreq[i] = afreq[i-1];
    afreq[i][a[i-1]-'a']++;
    
    bfreq[i] = bfreq[i-1];
    bfreq[i][b[i-1]-'a']++;
  }
  while (q--){
    int l,r;
    cin>>l>>r;
    int ops=0;
    for (int i=0;i<26;i++){
      int target = bfreq[r][i] - bfreq[l-1][i];
      int have = afreq[r][i] - afreq[l-1][i];
      ops += abs(target-have);
    }
    ops /= 2;
    cout << ops << endl;
  }
}

int main() {
  int t; cin>>t;
  while (t--){
    solve();
  }
}
