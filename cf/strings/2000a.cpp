#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin>>s;
    if (s.length() < 2 || s.substr(0, 2) != "10") {
      cout << "NO" << endl;
      continue;
    }
    string a = s.substr(2, s.length()-2);
    if (!a.empty() && a[0] != '0' && a != "1") {
      cout << "YES" << endl;
      continue;
    } 
    cout << "NO" << endl;
  }
}
