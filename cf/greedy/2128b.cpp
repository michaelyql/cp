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
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int l = 0, r = n - 1;
    int last = 0, inc = 0, dec = 0;
    while (l <= r) {
        int x = a[l], y = a[r];
        if (inc == 4) {
            if (x < last) {
                cout << "L";
                l++;
                last = x;
            } else {
                cout << "R";
                r--;
                last = y;
            }
            inc = 1;
            dec = 2;
            continue;
        } 
        else if (dec == 4) {
            if (x > last) {
                cout << "L";
                l++;
                last = x;
            } else {
                cout << "R";
                r--;
                last = y;
            }
            dec = 1;
            inc = 2;
            continue;
        }
        if (x > last && y > last) {
            if (x > y) {
                cout << "L";
                l++;
                last = x;
            } else {
                cout << "R";
                r--;
                last = y;
            }
            inc++;
            dec = 1;
        } else if (x > last && y < last) {
            cout << "L";
            l++;
            last = x;
            inc++;
            dec = 1;
        } else if (x < last && y > last) {
            cout << "L";
            l++;
            last = x;
            dec++;
            inc = 1;
        } else {
            if (x < y) {
                cout << "L";
                l++;
                last = x;
            } else {
                cout << "R";
                r--;
                last = y;
            }
            dec++;
            inc = 1;
        }
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
