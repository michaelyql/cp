#include <bits/stdc++.h>
#include <cmath>

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

random_device rnd;
mt19937 mt(rnd());
// usage: shuffle(all(a), mt)
// usage: uint32_t r = mt()

const double EPS = 1e-9;
const int INF = 2;
int n;

int gauss(vector<vector<double>>& a, vector<double>& b, vector<double>& ans) {
    vector<int> where(n, -1);
    for (int col = 0, row = 0; col < n && row < n; col++) {
        int sel = row;
        // select pivot row
        for (int i = row; i < n; i++) {
            if (abs(a[i][col]) > abs(a[sel][col])) sel = i;
        }
        if (abs(a[sel][col]) < EPS) continue;

        // swap rows
        for (int j = 0; j < n; j++) swap(a[row][j], a[sel][j]);
        swap(b[row], b[sel]);

        where[col] = row;

        // eliminate other rows in the column
        for (int i = 0; i < n; i++) {
            if (i == row) continue;
            double c = a[i][col] / a[row][col];
            for (int j = col; j < n; j++) {
                a[i][j] -= c * a[row][j];
            }
            b[i] -= c * b[row];
        }
        row++;
    }

    // assign values variables (ans is a particular solution)
    ans.assign(n, 0);
    vector<int> free_cols, basis_cols;
    for (int j = 0; j < n; j++) {
        if (where[j] != -1) {
            ans[j] = b[where[j]] / a[where[j]][j];
        }
    }

    // plug in values to each equation to check lhs == rhs
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) {
            sum += ans[j] * a[i][j];
        }
        if (abs(sum - b[i]) > EPS) return 0; // inconsistent
    }
    
    for (int j = 0; j < n; j++) {
        if (where[j] == -1) {
            return INF; // infinite solutions
        }
    }
    return 1; // 1 solution
}

void solve() {
    vector<vector<double>> a(n, vector<double>(n));
    rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
    vector<double> b(n);
    rep(i, 0, n) cin >> b[i];
    vector<double> ans(n, 0);
    int ret = gauss(a, b, ans);
    if (!ret) {
        cout << "inconsistent" << endl;
    } else if (ret == 1) {
        // cout<<"final matrix\n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<a[i][j]<<(j<n-1 ? " " : "");
        //     }
        //     cout<<endl;
        // }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i < n - 1 ? " " : "");
        }
        cout << endl;
    } else {
        cout << "multiple" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        if (!n) break;
        solve();
    }
}
