#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define loop(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	
	unordered_map<int, int> freq;
	loop(i, 0, n) 
	{
		cin >> a[i];
		freq[a[i]]++;
	}
	sort(a.begin(), a.end());

	int prev = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] != prev) {
			
			int diff = a[i] - prev; 
			
			if (freq[prev] >= 2) {
				
				if (freq[prev] - 1 >= diff * 2) {
					
					freq[a[i]] += freq[prev] - 2 - (diff - 1) * 2;	
					
				} else if (freq[prev] & 1) {
					cout << "NO" << endl;
					return;
				}
				
			} else {
				cout << "NO" << endl;
				return;
			}
			
			prev = a[i];
		} 
	}
	cout << "YES" << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
