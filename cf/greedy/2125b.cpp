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

ll gcd(ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

void solve() {  
    ll a, b, k;
    cin >> a >> b >> k;
    
    if (k >= a && k >= b) {
        cout << 1 << endl;
        return;
    } 
    
    ll g = gcd(a, b);
    if (g == 1) {
        cout << 2 << endl;
        return;
    }
    ll aa = a / g;
    ll bb = b / g;
    if (max(aa, bb) <= k) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
