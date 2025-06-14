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
    int n;
    cin >> n;
    for (ll k = 1; k <= n; k++) {
        ll total = (k * k) * (k * k - 1) / 2;
        total -= (k - 1) * 4 * (k - 2);
        cout << total << endl;
    }
}
