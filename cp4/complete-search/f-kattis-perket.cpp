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

int main() {
    int n;
    cin >> n;
    vi s(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> b[i];
    }
    int ans = 2e9;
    for (int mask = 1; mask < (1 << n); mask++) {
        int ss = 1, bb = 0;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                ss *= s[j];
                bb += b[j];
            }
        }
        ans = min(ans, abs(ss - bb));
    }
    cout << ans << endl;
}
