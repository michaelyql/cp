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

int a[46], b[46];

pii f(int n) {
    if (a[n] && b[n]) return {a[n], b[n]};
    if (n == 1) return {0, 1}; 
    pii p = f(n - 1);
    a[n] = p.second;
    b[n] = p.second + p.first; 
    return {a[n], b[n]};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int x, y;
    tie(x, y) = f(n);
    cout << x << " " << y << "\n";
}
