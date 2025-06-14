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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    ll n;
    cin >> n;
    cout << n << " ";
    while (n != 1) {
        if (n & 1) n = n * 3 + 1;
        else n /= 2;
        cout << n << " ";
    }
}
