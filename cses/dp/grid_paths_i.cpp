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

const int N = 1000;
int a[N][N], dp[N][N];

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr); 
    int n;
    cin >> n;
    string s;
    rep(i, 0, n) {
        cin >> s;
        rep(j, 0, n) a[i][j] = (s[j] == '.');
    }
    const int mod = 1e9 + 7;
    dp[0][0] = a[0][0];
    rep(i, 0, n) {
        rep(j, 0, n) {
            rep(k, 0, 2) {
                int nr = i + dy[k];
                int nc = j + dx[k];
                if (nr < n && nc < n && a[nr][nc]) {
                    dp[nr][nc] = (dp[nr][nc] + dp[i][j]) % mod;
                }  
            }
        }
    }
    cout << dp[n-1][n-1] << endl;
}
