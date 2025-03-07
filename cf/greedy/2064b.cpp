#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	unordered_map<int, int, custom_hash> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	vector<pii> candidates;
	for (int i = 0; i < n;) {
		if (mp[a[i]] == 1) {
			int j = i;
			while (j < n && mp[a[j]] == 1) j++;
			j--;
			candidates.push_back({ i, j });
			i = j + 1;
		} else {
			i++;
		}
	}
	sort(candidates.begin(), candidates.end(), [](const pii& p1, const pii& p2) {
		return (p1.second - p1.first) > (p2.second - p2.first);	
	});
	if (candidates.empty()) cout << 0 << endl;
	else {
		cout << candidates[0].first + 1 << " " << candidates[0].second + 1 << endl;
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
