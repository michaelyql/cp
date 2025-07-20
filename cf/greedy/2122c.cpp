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

int n;

void solve() {
    cin >> n;
    vector<array<int, 3>> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i][0] >> pts[i][1];
        pts[i][2] = i + 1;
    }
    sort(all(pts), [](array<int, 3>& p1, array<int, 3>& p2) {
        if (p1[0] != p2[0]) return p1[0] < p2[0];
        return p1[1] < p2[1];
    });
    vector<array<int, 3>> a1, a2;
    rep(i, 0, n / 2) a1.push_back(pts[i]);
    rep(i, n / 2, n) a2.push_back(pts[i]);
    
    sort(a1.begin(), a1.end(), [](array<int, 3>& p1, array<int, 3>& p2) {
        return p1[1] < p2[1];
    });
    sort(a2.begin(), a2.end(), [](array<int, 3>& p1, array<int, 3>& p2) {
        return p1[1] > p2[1];
    }); 
    for (int i = 0; i < n / 2; i++) {
        cout << a1[i][2] << " " << a2[i][2] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
