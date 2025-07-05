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
    int l[4], b[4]; // b for width, l for height
    for (int i = 1; i <= 3; i++) {
        cin >> b[i] >> l[i];
    }
    // check single col/row
    if ((l[1] == l[2] 
        && l[1] == l[3]
        && l[1] == b[1] + b[2] + b[3]) 
        || 
        (b[1] == b[2]
        && b[1] == b[3]
        && b[1] == l[1] + l[2] + l[3])
    ) {
        cout << "YES" << endl;
        return;
    }

    // check stacks of 2
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (j == i) continue;
            for (int k = 1; k <= 3; k++) {
                if (k == j || k == i) continue;
                if (b[j] == b[k] && b[i] + b[j] == l[i] && l[i] == l[j] + l[k]) {
                    cout << "YES" << endl;
                    return;
                }
                if (b[j] + b[k] == b[i] && l[j] == l[k] && b[i] == l[i] + l[j]) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
