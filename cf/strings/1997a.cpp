#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
    cin>>s;
    if (s.length()==1) {
      cout << (s[0] == 'a' ? 'b' : 'a') + s << endl;
      return;
    }
  for (int i=0;i<s.length()-1;i++){
      if (s[i]==s[i+1]) {
        cout << s.substr(0,i+1) + (s[i]=='a'?'b':'a') + s.substr(i+1, s.length()-i-1) << endl;
        return;
    }
  }
  cout << s + (s.back()=='a'?'b':'a') << endl;
}
int main() {
  int t;
  cin>> t;
  while(t--){
    solve();
  }
}
