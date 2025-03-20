#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> o(n), a(n); // o for original order
	int v;
	rep(i, 0, n) {
		cin >> v;
		o[i] = a[i] = v;
	}
	ll sum = accumulate(a.begin(), a.end(), 0ll);
	if (k > sum) {
		cout << -1 << endl;
		return;
	}
	if (k == sum) {
		cout << endl;
		return;
	}
	sort(a.begin(), a.end());
	ll r = n; // animals remaining in the queue
	ll acc = 0; // number of stages passed
	int i = 0;
	while (i < n && (a[i] - acc) * r <= k) {
		k -= (a[i] - acc) * r;
		acc = a[i];
		int j = i + 1;
		while (j < n && a[j] == a[i]) j++;
		r -= (j - i);
		i = j;
	}
	if (k == 0) {
		vector<int> ans;
		rep(j, 0, n) {
			if (o[j] > acc) ans.push_back(j + 1);
		}
		for (int x : ans) cout << x << " ";
		cout << endl;
		return;	
	} 
	ll hi = a[i] - acc - 1, lo = 0;
	ll p = 0;
	while (lo <= hi) {
		ll mid = lo + (hi - lo) / 2;
		if (mid * r <= k) {
			p = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	k -= p * r;
	acc += p;
	vector<int> back;
	vector<int> ans;
	rep(j, 0, n) {
		if (k == 0) {
			if (o[j] > acc) ans.push_back(j + 1);
		} else {
			if (o[j] - 1 == acc) {
				k--;
			} else if (o[j] - 1 > acc) {
				k--;
				back.push_back(j + 1); 
			}
		}
	}
	for (int x : back) ans.push_back(x);
	for (int x : ans) cout << x << " ";
	cout << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	solve();
}
