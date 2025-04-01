#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 1e7 + 5;
bool isPrime[N];
int spf[N];
vector<int> primes;

void sieve() {
	for (int i = 0; i < N; i++) isPrime[i] = true;
	for (int i = 2; i < N; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
			spf[i] = i;
		}
		for (int j = 0; j < primes.size() && 1ll * i * primes[j] < N && primes[j] <= spf[i]; j++) {
			isPrime[1ll * i * primes[j]] = false;
			spf[1ll * i * primes[j]] = primes[j];
		}
	}
}

void solve() {
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) ans += n / i;
	}
	cout << ans << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	sieve();
	int t;
	cin >> t;
	while (t--) solve();
}
