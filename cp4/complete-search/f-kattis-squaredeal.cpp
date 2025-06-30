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
    int h[4], w[4];
    for (int i = 1; i <= 3; i++) {
        cin >> h[i] >> w[i];
    }
    // check single row/column 
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                if ((w[1] == w[2] && w[1] == w[3] && w[1] == h[1] + h[2] + h[3])
                    || 
                    (h[1] == h[2] && h[1] == h[3] && h[1] == w[1] + w[2] + w[3])) {
                    cout << "YES" << endl;
                    return 0;
                }
                swap(h[3], w[3]);
            }
            swap(h[2], w[2]);
        }
        swap(h[1], w[1]);
    }

    // check two stack + one left/right/top/bottom

    // pick first rectangle
    for (int i = 1; i <= 3; i++) {
        for (int ii = 0; ii < 2; ii++) {

            // pick second rect
            for (int j = 1; j <= 3; j++) {
                if (j == i) continue; 
                for (int jj = 0; jj < 2; jj++) {

                    // pick third
                    for (int k = 1; k <= 3; k++) {
                        if (k == i || k == j) continue;
                        for (int kk = 0; kk < 2; kk++) {

                            if (h[j] + h[k] == h[i] 
                                && w[j] == w[k] 
                                && w[i] + w[j] == h[i]) {
                                cout << "YES" << endl;
                                return 0;
                            }

                            if (w[j] + w[k] == w[i] 
                                && h[j] == h[k] 
                                && h[i] + h[j] == w[i]) {
                                cout << "YES" << endl;
                                return 0;
                            }

                            swap(h[k], w[k]);
                        }
                    }
                    swap(h[j], w[j]);
                }
            }
            swap(h[i], w[i]);
        }
    }

    cout << "NO" << endl;
}
