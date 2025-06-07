#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
#define LSOne(S) ((S) & -(S)) 
#define all(x) (x).begin(), (x).end()
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
using vll = vector<ll>;

ll f(int i, vector<array<int, 3>>& intervals, vi& p, vll& dp) {
    if (i == 0) return 0;
    if (dp[i]) return dp[i];
    return dp[i] = max(
        intervals[i][2] + f(p[i], intervals, p, dp),
        f(i - 1, intervals, p, dp)
    );
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr); 
    int n;
    cin >> n;
    vi l(n + 1), r(n + 1), v(n + 1); // left and right boundary + value 
    vector<array<int, 3>> intervals;
    intervals.push_back({0, 0, 0}); // filler node
    rep(i, 1, n + 1) {
        cin >> l[i] >> r[i] >> v[i];
        intervals.push_back({l[i], r[i], v[i]});
    }
    // sort by right endpoint, break ties by left
    sort(all(intervals), [](const array<int, 3>& i1, const array<int, 3>& i2) {
        if (i1[1] == i2[1] && i1[0] == i2[0]) return i1[2] < i2[2];
        if (i1[1] == i2[1]) return i1[0] < i2[0];
        return i1[1] < i2[1];
    });
    vi p(n + 1); // right-most i such that i < j and j is compatible with i
    map<int, set<int>> right_endpoints; // right endpoint and it's index
    rep(i, 1, n + 1) {
        auto it = right_endpoints.lower_bound(intervals[i][0]);
        if (it != right_endpoints.begin()) {
            it--;
            p[i] = *(*it).second.rbegin();
        }
        right_endpoints[intervals[i][1]].insert(i);
    }
    vll dp(n + 1);
    cout << f(n, intervals, p, dp);
}
