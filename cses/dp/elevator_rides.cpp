#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 20;
pii best[1 << N];

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	
	for (int i = 0; i < n; i++) cin >> a[i];
	
	best[0] = {1, 0};

	for (int s = 1; s < 1 << n; s++) {
		best[s] = {n + 1, 0};
		for (int i = 0; i < n; i++) {
			if (s & (1 << i)) {
				// copy of prev best 
				pair<int, int> prev = best[s - (1 << i)];
				
				if (prev.second + a[i] > x) {
					prev.first++;
					prev.second = a[i];
				} else {
					prev.second += a[i];
				}
				
				best[s] = min(best[s], prev);	
			}
		}
	}

	cout << best[(1 << n) - 1].first << endl;
}
