#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 1e7 + 5;

bool isPrime[N];
vector<int> primes;
int spf[N];

void sieve() {
	rep(i, 0, N) isPrime[i] = true;
	for (int i = 2; i < N; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
			spf[i] = i;
		}
		
		for (int j = 0; j < primes.size() 
			&& 1ll*i*primes[j] < N 
			&& primes[j] <= spf[i]; j++) {
			isPrime[1ll*i*primes[j]] = false;
			spf[1ll*i*primes[j]] = primes[j];
		}
	}
}

int main() {
  sieve();
  rep(i, 0, primes.size()) cout << primes[i] << " ";
  cout << endl;
}
