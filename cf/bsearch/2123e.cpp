#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
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
using vvll = vector<vector<ll>>;
using vb = vector<bool>;

void solve() {
    int n;
    cin >> n;
    int mex = 0;
    vector<int> c(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        c[x]++;
        while (c[mex]) mex++;
    }
    set<int> s;
    map<int, vector<int>> freq;
    for (int i = 0; i < n; i++) {
        freq[c[i]].push_back(i);
    }
    s.insert(mex);
    cout << 1 << " ";
    for (int k = 1; k <= n; k++) {
        s.erase(n - k + 1);
        for (int j: freq[k]) {
            if (j <= min(mex, n - k)) {
                s.insert(j);
            }
        }
        cout << s.size() << " ";
    } 
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
