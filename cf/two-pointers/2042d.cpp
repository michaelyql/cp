#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using interval = array<int, 3>;

struct pair_hash {
	size_t operator()(const pii& p) const {
		size_t seed = 0;
		seed ^= hash<int>{}(p.first) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		seed ^= hash<int>{}(p.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		return seed;
	}
};

struct pair_equal {
	bool operator()(const pii& p1, const pii& p2) const {
		return p1.first == p2.first && p1.second == p2.second;
	}
};

void solve() {
	// cout<<"---\n";
	int n;
	cin >> n;
	vector<interval> intervals;
	unordered_map<pii, int, pair_hash, pair_equal> cnt; 
	
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		intervals.push_back({ l, r, i });
		cnt[{l, r}]++;
	}
	sort(intervals.begin(), intervals.end(), [](const interval& i1, const interval& i2) {
		if (i1[0] == i2[0]) return i1[1] > i2[1];
		else return i1[0] < i2[0]; 
	});
	set<int> right_ends;
	vector<int> ans(n, 0);
	for (int i = 0; i < n; i++) {
		// cout<<"current interval:["<<intervals[i][0]<<", "<<intervals[i][1]<<"]"<<endl;
		if (!right_ends.empty()) {
			auto it = right_ends.lower_bound(intervals[i][1]); 
			if (it != right_ends.end()) {
				// cout<<"Rj="<<*it<<endl;
				ans[intervals[i][2]] += *it - intervals[i][1]; 
			}
		}
		right_ends.insert(intervals[i][1]);
	}
	sort(intervals.begin(), intervals.end(), [](const interval& i1, const interval& i2) {
		if (i1[1] == i2[1]) {
			return i1[0] < i2[0]; 
		}	
		return i1[1] > i2[1];
 	});
 	set<int, greater<int>> left_ends;
 	for (int i = 0; i < n; i++) {
 		// cout<<"current interval:["<<intervals[i][0]<<", "<<intervals[i][1]<<"]"<<endl;
 		if (!left_ends.empty()) {
 			auto it = left_ends.lower_bound(intervals[i][0]);
 			if (it != left_ends.end()) {
 				// cout<<"Lj="<<*it<<endl;
 				ans[intervals[i][2]] += intervals[i][0] - *it;
 			}
 		}
 		left_ends.insert(intervals[i][0]); 
 	}
 	vector<int> ok(n, true);
 	for (int i = 0; i < n; i++) {
 		int l = intervals[i][0];
 		int r = intervals[i][1];
 		if (cnt[{l, r}] > 1) ok[intervals[i][2]] = false;
 	}
 	for (int i = 0; i < n; i++) {
 		if (!ok[i]) cout << 0 << endl;
 		else cout << ans[i] << endl;
 	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
