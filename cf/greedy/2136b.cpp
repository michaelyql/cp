#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
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
using uint = unsigned int;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// usage: shuffle(all(a), rng)
// usage: uint32_t r = rng()

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 1) {
        for (char& x : s) if (x == '1') { cout << "NO" << endl; return; }
        cout << "YES" << endl;
        for (int i = n; i >= 1; i--) cout << i << " ";
        cout << endl;
    } else {
        int i = 0;
        while (i < n) {
            while (i < n && s[i] == '0') i++;
            int j = i;
            while (j < n && s[j] == '1') j++;
            if (j - i >= k) { cout << "NO" << endl; return; }
            else i = j; 
        }
        int b = n;
        int a = 1;
        cout << "YES" << endl;
        for (char& x : s) { 
            if (x == '0') { 
                cout << b << " "; 
                b--; 
            } 
            else { 
                cout << a << " "; 
                a++; 
            } 
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
