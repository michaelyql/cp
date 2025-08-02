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
    int n, s;
    cin >> n >> s;
    vi a(n);
    int sum = 0;
    int ones = 0, twos = 0, zeros = 0;
    rep(i, 0, n) {
        cin >> a[i];
        sum += a[i];
        if (a[i] == 1) ones++;
        else if (a[i] == 2) twos++;
        else zeros++;
    }
    if (sum == s) {
        cout << -1 << endl;
        return;
    }
    if (sum > s) {
        rep(i, 0, n) cout << a[i] << " ";
        cout << endl;
        return;
    }
    // sum < s
    if (sum == s - 1) {
        if (!zeros) { 
            rep(i, 0, n) cout << a[i] << " ";
            cout << endl;
            return;
        } 
        if (!ones) {
            rep(i, 0, n) cout << a[i] << " ";
            cout << endl;
            return;
        }
        if (twos) {
            while (zeros--) cout << 0 << " ";
            while (twos--) cout << 2 << " ";
            while (ones--) cout << 1 << " ";
            cout << endl;
            return; 
        }
        cout << -1 << endl;
        return;
    }
    int diff = s - sum;
    if (diff & 1) {
        // prevent 0-1 transitions, diff >= 3
        if (!ones) {
            rep(i, 0, n) cout << a[i] << " ";
            cout << endl;
            return;  
        }
        if (zeros) {
            cout << -1 << endl;
            return;
        } else {
            if (!twos) {
               rep(i, 0, n) cout << a[i] << " ";
                cout << endl;
                return;   
            }
            cout << -1 << endl;
        }
    } else {
        // diff >= 2
        if (zeros) {
            if (ones || twos) {
                cout << -1 << endl;
                return;
            }
            rep(i, 0, n) cout << a[i] << " ";
            cout << endl;
            return;  
        } else {
            if (!twos) {
                cout << -1 << endl;
                return;
            }
            if (!ones) {
                if (diff % 4 == 0) {
                    cout << -1 << endl;
                    return;
                }
                rep(i, 0, n) cout << a[i] << " ";
                cout << endl;
                return;  
            }
            if (twos < ones - 1) {
                cout << -1 << endl;
                return;
            }
            if (diff % 3 == 0) {
                cout << -1 << endl;
                return;
            }
            if (diff == 2) {
                rep(i, 0, n) cout << a[i] << " ";
                cout << endl;
                return;   
            }
            if (twos > ones + 1) {
                cout << -1 << endl;
                return;
            } 
            if (twos > ones) {
                for (int i = 0; i < n; i++) {
                    if (i) cout << 2 << " ";
                    else cout << 1 << " ";
                }
                cout << endl;
            } else {
                for (int i = 0; i < n; i++) {
                    if (i) cout << 1 << " ";
                    else cout << 2 << " ";
                }
                cout << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
