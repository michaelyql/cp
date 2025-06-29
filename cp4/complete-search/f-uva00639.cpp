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
    vector<string> board(n);
    rep(i, 0, n) {
        cin >> board[i];
    }
    const int total_cells = n * n;
    int mask = 1;
    int ans = 0;

    for (; mask < (1 << total_cells); mask++) {
        bool valid_mask = true;

        for (int i = 0; i < n; i++) {
            bool has = false;
            // check row violations
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << (i * n + j)))) {
                    if (board[i][j] == 'X' || has) {
                        valid_mask = false;
                        break;
                    }
                    has = true;
                } else {
                    if (board[i][j] == 'X') has = false;
                }
            }
            if (!valid_mask) break;

            // check column violations
            has = false;
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << (j * n + i)))) {
                    if (board[j][i] == 'X' || has) {
                        valid_mask = false;
                        break;
                    }
                    has = true;
                } else {
                    if (board[j][i] == 'X') has = false;
                }
            }
            if (!valid_mask) break;
        }
        if (valid_mask) {
            int pieces = 0;
            for (int i = 0; i < total_cells; i++) {
                if (mask & (1 << i)) pieces++;
            }
            ans = max(ans, pieces);
        }
    }
    cout << ans << endl;
}

int main() {
    while (cin >> n && n) {
        solve();
    }
}
