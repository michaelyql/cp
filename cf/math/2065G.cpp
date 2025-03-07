// referring to editorial

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 2;

// prevent hacking
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_set<int> primes;
vector<int> ordered_primes;

unordered_map<int, int, custom_hash> freq; // prime freq

void sieve(int n) {
	vector<bool> isPrime(n + 1, true);
	for (int i = 2; i * i <= n; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			primes.insert(i);
			ordered_primes.push_back(i);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	freq.clear();
	
	vector<vector<int>> factors; // prime factors of semiprimes

	vector<int> p; // vector of primes only
	
	for (int i = 1; i <= n; i++) {
		if (primes.find(a[i]) != primes.end()) {
			freq[a[i]]++; // increment frequency of prime
			p.push_back(a[i]);
		} else {
			int p1 = 0, p2 = 0;
			// factorize the composite number
			for (int i = 0; i < ordered_primes.size(); i++) {
				if (ordered_primes[i] * ordered_primes[i] > a[i]) break;
				if (a[i] % ordered_primes[i] == 0 && 
					primes.find(a[i] / ordered_primes[i]) != primes.end()) {
					p1 = ordered_primes[i];
					p2 = a[i] / ordered_primes[i];
					break;
				}
			}
			// if a[i] is semiprime
			if (p1) {
				// increment the frequency
				spf[a[i]]++;
				factors.push_back({p1, p2, a[i]}); 
			} 
		}
	}
	
	int P = p.size(); // total number of primes in the array
	
	// calculate contribution of primes with other primes
	int p_ans = 0;
	for (int i = 0; i < P i++) {
		p_ans += pf[p[i]] * (P - pf[p[i]]) / 2; // divide by 2 to remove overcounting
	}
	
	// calculate contribution of semiprimes
	int sp_ans = 0;
	for (int i = 0; i < factors.size(); i++) {
		// semiprime with itself
		int sp = factors[i][2];
		sp_ans += spf[sp] * (spf[sp] + 1) / 2; // sum of AP sequence 1 + 2 + ... + spf[sp]
		
		// semiprime with its prime factors 
		// spf[sp] * 
	}
	
	cout << ans << endl;
}

int main() {
	sieve(N);
	int t;
	cin >> t;
	while (t--) solve();
}
 
