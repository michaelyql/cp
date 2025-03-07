#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;cin>>n;
  unordered_map<int,int> m;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    m[x]++;
  }
  int ones=0;
  int others=0;
  for(auto it=m.begin();it!=m.end();it++){
    if (it->second==1) ones++;
    else others++;
  }
  cout << 2*((ones+1)/2) + others << endl;
}

int main() {
  int t;cin>>t;
  while(t--)solve();
}
