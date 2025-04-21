#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
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

void solve() {
	int n;
	cin >> n;
	vi a(n);
	map<int, ll> pcnt;
	map<pair<int, pii>, ll> spcnt;
	ll tp = 0; 
	rep(i, 0, n) {
		cin >> a[i];
		int p = 2, x = a[i];
		vector<int> primes;
		while (p * p <= x) {
			if (x % p == 0) {
				while (x % p == 0) {
					x /= p;
					primes.push_back(p);
				}
			}
			p++;
		}
		if (x > 1) primes.push_back(x);
		if (primes.size() == 1) {
			pcnt[a[i]]++;
			tp++;
		} else if (primes.size() == 2) {
			spcnt[{a[i], {primes[0], primes[1]}}]++;
		}
	}
	ll s1 = 0;
	for (auto it = pcnt.begin(); it != pcnt.end(); it++) {
		ll c = (*it).second;
		s1 += c * (tp - c);
	}
	s1 /= 2;
	ll s2 = 0, s3 = 0;
	for (auto it = spcnt.begin(); it != spcnt.end(); it++) {
		ll c = (*it).second; 
		s3 += c * (c + 1) / 2;
		
		pii primes = (*it).first.second;
		if (primes.first != primes.second) {
			s2 += c * (pcnt[primes.first] + pcnt[primes.second]);
		} else {
			s2 += c * pcnt[primes.first];
		}
	}
	ll ans = s1 + s2 + s3;
	cout << ans << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
