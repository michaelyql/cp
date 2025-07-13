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

const int mod = 1e9 + 7;

ll modpow(ll a, ll b) {
    if (b == 0) return 1;
    ll ret = 1;
    while (b > 0) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;   
    }
    return ret;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vll a(n + 2);
    ll pow = 1, cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        ll next = ((s[i] - '0') * pow % mod + cur) % mod;
        a[i] = (a[i + 1] + next) % mod;
        cur = next;
        pow = pow * 10 % mod;
    }
    ll tot = 0, psum = 0;
    ll modinv = modpow(9, mod - 2);
    tot = (tot + a[1]) % mod;
    for (int i = 0; i < n; i++) {
        psum = psum * 10 % mod + (s[i] - '0');
        ll pre = psum * (modpow(10, n - i - 1) - 1) % mod * modinv % mod;
        tot = (tot + pre) % mod;
        tot = (tot + a[i + 2]) % mod;
    }
    cout << tot << endl;
}
