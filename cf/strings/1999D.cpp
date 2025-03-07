#include <bits/stdc++.h>
using namespace std;

void solve(){
  string a,b;
    cin>>a>>b;
    int k=0;
    int n=a.length();
    for (int i=0;i<n;i++){
      if(k==b.length()) {
        if (a[i]=='?') a[i]='a';
        else continue;
      }
      if (a[i]==b[k]) {
        k++;
        continue;
      }
      if (a[i]=='?') {
        a[i]=b[k];
        k++;
        continue;
      }
    }
    if (k==b.length()) {
      cout << "YES\n";
      cout << a << endl;
    }
    else cout << "NO\n";
}
int main(){
  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
