#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 2e5 + 7;
bool isPrime[N];
vector<int> primes;
int spf[N];

void fast_sieve() {
	rep(i, 2, N) isPrime[i] = true;
	for (int i = 2; i < N; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
			spf[i] = i;
		}
		
		for (int j = 0; j < primes.size() && 
			1ll * i * primes[j] < N && 
			primes[j] <= spf[i]; j++) {
			isPrime[1ll * i * primes[j]] = false;
			spf[1ll * i * primes[j]] = primes[j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	fast_sieve();
	int k;
	cin >> k;
	if (k < 3) {
		cout << 1 << endl;
		rep(i, 0, k) cout << 1 << " ";
		cout << endl;
	} else {
		cout << 2 << endl;
		rep(i, 1, k + 1) {
			if (isPrime[i + 1]) cout << 1 << " ";
			else cout << 2 << " ";
		}
		cout << endl;
	}
}
