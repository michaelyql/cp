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
    string s;
    cin >> n >> s;
    ll a = 0, ab = 0, abc = 0, p = 1;
    const int mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') a = (a + p) % mod;
        else if (s[i] == 'b') ab = (ab + a) % mod;
        else if (s[i] == 'c') abc = (abc + ab) % mod;
        else {
            abc = (abc * 3 % mod + ab) % mod;
            ab = (ab * 3 % mod + a) % mod;
            a = (a * 3 % mod + p) % mod;
            p = p * 3 % mod;
        }
    }
    cout << abc << endl;
}
