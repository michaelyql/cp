// my attempt

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e3 + 1;
int M[N][N];
ll diag1[2 * N], diag2[2 * N];
ll v[2];
pair<int, int> p[2] = {{1, 1}, {1, 2}};

inline void f(int c, int i, int j, ll score) {
  if (score > v[c]) {
    v[c] = score;
    p[c].first = i;
    p[c].second = j;
  }
}

int main() {

  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> M[i][j];
      diag1[i + j] += M[i][j]; // left to right upwards diagonal
      diag2[n + i - j] += M[i][j]; // left to right downwards diagonal
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      f((i + j) & 1, i + 1, j + 1, diag1[i + j] + diag2[n + i - j] - M[i][j]);
    } 
  }
  cout << v[0] + v[1] << endl;
  cout << p[0].first << " " << p[0].second << " " << p[1].first << " " << p[1].second << endl;
}


// model solution

// #include <iostream>
// #include <cstdio>
 
// using namespace std;
// const int NMAX = 2014;
// long long d1[2*NMAX], d2[2*NMAX], sol[2];
// pair < int , int > v[2];
// int a[NMAX][NMAX];
// inline void Update(const int c,const int i,const int j,const long long val){
//     if(val > sol[c]){
//         sol[c] = val;
//         v[c].first = i;
//         v[c].second = j;
//     }
// }
// int main(){
//     #ifndef ONLINE_JUDGE
//         freopen("date.in","r",stdin);
//         freopen("date.out","w",stdout);
//     #endif
//     cin.sync_with_stdio(false);
//     int n;
//     cin >> n;
//     sol[0] = sol[1] = -1; 
//     for(int i = 1;i <= n; ++i)
//         for(int j = 1;j <= n; ++j){
//             int x;
//             cin >> a[i][j];
//             d1[i+j] += a[i][j];
//             d2[i-j+n] += a[i][j];
//         }
//     for(int i=1;i<=n;++i)
//         for(int j=1;j<=n;++j)
//             Update((i+j)&1,i,j,d1[i+j]+d2[i-j+n]-a[i][j]);
//     cout<<sol[0]+sol[1]<<"\n";
//     if(v[0] > v[1])
//         swap(v[0],v[1]);
//     cout<<v[0].first<<" "<<v[0].second<<" ";
//     cout<<v[1].first<<" "<<v[1].second<<"\n";
//     return 0;
// }
