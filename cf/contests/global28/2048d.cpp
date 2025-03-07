#include <bits/stdc++.h>
using namespace std;

// not passing

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  int k_rating;
  cin >> k_rating; // kevin's rating
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  // number of ppl with greater rating than kevin
  int c = a.end() - upper_bound(a.begin(), a.end(), k_rating); 

  if (c == 0) {
    for (int i = 1; i <= m; i++) {
      cout << (m / i) << endl;
    }
    return;
  }

  for (int i = 1; i <= m; i++) {
    int sum = 0;
    int couldnt_solve = *upper_bound(b.begin(), b.end(), k_rating); // difficulty of first problem kevin couldnt solve
    int ranking = 1 + c - (a.end() - upper_bound(a.begin(), a.end(), couldnt_solve));

    int num_solved = upper_bound(b.begin(), b.end(), k_rating) - b.begin();  
    
    int num_contests = m / i;
    if (i == 1) {
      // no. of problems kevin solved == no. of contest where his rank is 1
      sum += num_solved;
      
      sum += (m - num_solved) * ranking;
    } else {
      sum += (num_solved / i); // rank is 1 here
      sum += (num_contests - (num_solved / i)) * ranking;
    }
    cout << sum << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
