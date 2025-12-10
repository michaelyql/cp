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
            basis_cols.push_back(j);
        } else {
            free_cols.push_back(j);
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

    // find nullspace vectors by back substitution
    vector<vector<double>> nullspace;

    for (int f : free_cols) {
        vector<double> v(n, 0.0);
        v[f] = 1.0;
        for (int k = basis_cols.size() - 1; k >= 0; --k) {
            int col = basis_cols[k];
            int row = where[col];
            double sum = 0;
            for (int j = col+1; j < n; ++j) sum += a[row][j] * v[j];
            v[col] = -sum / a[row][col];
        }
        nullspace.push_back(v);
    }
   
    for (int j = 0; j < n; j++) {
        if (where[j] != -1) {
            for (auto& v : nullspace) {
                if (abs(v[j]) > EPS) {
                    ans[j] = -1;
                    break;
                }
            }
        } else {
            ans[j] = -1;
        }
    }

    return 1; // ok (1 or infinite solutions)
}

void solve() {
    vector<vector<double>> a(n, vector<double>(n));
    rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
    vector<double> b(n);
    rep(i, 0, n) cin >> b[i];
    vector<double> ans(n, 0);
    int ok = gauss(a, b, ans);
    if (!ok) {
        cout << "inconsistent" << endl;
    } else {
        // cout<<"final matrix\n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<a[i][j]<<(j<n-1 ? " " : "");
        //     }
        //     cout<<endl;
        // }

        for (int i = 0; i < n; i++) {
            if (ans[i] != -1) cout << ans[i]; 
            else cout << "?";
            cout << (i < n - 1 ? " " : "");
        }
        cout << endl;
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
