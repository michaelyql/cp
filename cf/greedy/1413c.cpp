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
    int a[6];
    rep(i, 0, 6) cin >> a[i];
    int n; 
    cin >> n;
    int b[n];
    vector<pii> p;
    rep(i, 0, n) {
        cin >> b[i];
        for (int j = 0; j < 6; j++) { 
            if (a[j] < b[i]) {
                p.push_back({b[i] - a[j], i});
            }
        }
    }
    sort(all(p));
    int l = 0, r = 0;
    map<int, int> notes;
    map<int, int> frets;
    int ans = 2e9;
    int k = p.size();
    while (r < k) {
        while (notes.size() < n && r < k) {
            frets[p[r].first]++;
            notes[p[r].second]++;
            if (notes.size() == n) break;
            r++;
        }
        while (notes.size() == n && l <= r) {
            int lo = frets.begin()->first;
            int hi = frets.rbegin()->first;
            ans = min(ans, hi - lo);

            frets[p[l].first]--;
            if (!frets[p[l].first]) frets.erase(p[l].first);

            notes[p[l].second]--;
            if (!notes[p[l].second]) notes.erase(p[l].second);
            l++;
        }
        r++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
