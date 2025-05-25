#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
#define LSOne(S) ((S) & -(S)) 
#define all(x) (x).begin(), (x).end()
#define debug
 
#ifdef debug
#define db(x) cout << #x " = " << x << endl;
#define bp(x) cout << #x << endl;
#else 
#define db(x) 
#define bp(x)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

/*

the cost to make all elements of an array equal to x 
where each increment/decrement by 1 costs 1 
is modeled by the expression

Σ |a_i - x| 

which is equal to the sum of absolute deviations. 

the minimum cost is achieved when x is equal to the median of the array.

https://math.stackexchange.com/questions/113270/the-median-minimizes-the-sum-of-absolute-deviations-the-ell-1-norm

https://www.quora.com/Why-does-the-median-minimize-the-sum-of-absolute-deviations

also: 

the mean minimizes the sum of squared deviations.

*/

void ins(int x, int n, int k, multiset<int>& up, multiset<int>& low, ll& up_sum, ll& low_sum) {
  int v = *low.rbegin();
  if (x > v) {
    up.insert(x);
		up_sum += x;
    if (up.size() > k / 2) {
      auto it = up.begin();
			
			low_sum += *it;
			up_sum -= *it;

      low.insert(*it);
      up.erase(it);
    }  
  } else {
    low.insert(x);
		low_sum += x;
    if (low.size() > (k + 1) / 2) {
      up.insert(v);
      low.erase(low.find(v));

			up_sum += v;
			low_sum -= v;
    }
  }
}

void remove(int x, int n, int k, multiset<int>& up, multiset<int>& low, ll& up_sum, ll& low_sum) {
  auto it = low.find(x);
  if (it != low.end()) {
		low_sum -= x;
    low.erase(it);
  } else {
    it = up.find(x);
		up_sum -= x;
    up.erase(it);
  }
  if (low.empty()) {
		it = up.begin();
		int v = *it;

    low.insert(*it);
    up.erase(it);

		low_sum += v;
		up_sum -= v;
  }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int n, k;
	cin >> n >> k;

  vi a(n);
  rep(i, 0, n) cin >> a[i];
  
	multiset<int> up, low;
	ll us = 0, ls = 0;

  low.insert(a[0]);
	ls += a[0];

  rep(i, 1, k) ins(a[i], n, k, up, low, us, ls);
  cout << us - ls + (k % 2  == 0 ? 0 : *low.rbegin()) << " ";

  rep(i, 1, n - k + 1) {
    if (k == 1) {
      cout << 0 << " ";
      continue;
    }
    remove(a[i - 1], n, k, up, low, us, ls);
    ins(a[i + k - 1], n, k, up, low, us, ls);
    cout << us - ls + (k % 2 == 0 ? 0 : *low.rbegin()) << " ";
  }
}
