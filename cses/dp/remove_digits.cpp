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

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr); 
    int n;
    cin >> n;
    const int inf = 1e9;
    vector<int> dp(n + 1, inf);
    dp[n] = 0;
    string s;
    for (int i = n; i > 0; i--) {
        s = to_string(i);
        for (char c : s) {
            int j = c - '0';
            dp[i - j] = min(dp[i - j], dp[i] + 1);
        }
    }
    cout << dp[0] << endl;
}
