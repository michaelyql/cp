#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++)

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    k--;

    /**
     * if x < 2^k then no, 
     * else yes
     * 
     * translates to
     * 
     * if log2(x) < k then no,
     * else yes
     * 
     * log2(x) can be though of as how many times to divide x by 2 before it reaches 0
     * i.e. the index of the msb in x
     */
    
    int idx = 31 - __builtin_clz(x);
    if (idx < k) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
	// your code goes here
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
