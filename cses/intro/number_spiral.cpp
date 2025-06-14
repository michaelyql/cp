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
using vb = vector<bool>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int t;
    cin >> t;
    ll x, y;
    while (t--) {
        cin >> x >> y;
        ll z = max(x, y);
        ll lim = z * z;
        ll low = (z - 1) * (z - 1) + 1;
        if (x > y) {
            if (x % 2 == 0) {
                cout << lim - y + 1 << endl;
            } else {
                cout << low + y - 1 << endl;
            }
        } else {
            if (y & 1) {
                cout << lim - x + 1 << endl;
            } else {
                cout << low + x - 1 << endl;
            }
        }
    }
}
