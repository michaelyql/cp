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
using vvll = vector<vll>;

const int N = 1e3 + 5;
int t[N][N];

int query(int y, int x) {
    int ret = 0;
    for (; y > 0; y -= y & -y) {
        int p = x;
        for (; p > 0; p -= p & -p) {
            ret += t[y][p];
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n, q;
    cin >> n >> q;
    rep(i, 0, n) {
        string s;
        cin >> s;
        rep(j, 0, n) {
            if (s[j] == '*') {
                for (int p = i + 1; p <= n; p += p & (-p)) {
                    for (int q = j + 1; q <= n; q += q & (-q)) {
                        t[p][q] += 1;
                    }
                }
            }
        }
    }
    rep(i, 0, q) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << query(y2, x2) - query(y2, x1 - 1) - query(y1 - 1, x2) + query(y1 - 1, x1 - 1) << endl;
    }
}
