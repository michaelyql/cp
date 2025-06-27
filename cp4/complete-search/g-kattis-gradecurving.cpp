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

// i hate this question

double f(double x) {
    return sqrt(x) * 10;
}

int main() {
    double x;
    int ylo, yhi;
    cin >> x >> ylo >> yhi;
    int k = 0;
    while ((int) ceil(x) < ylo) {
        double next = f(x);
        if ((int) ceil(next) > yhi) {
            cout << "impossible" << endl;
            return 0;
        }
        x = next;
        k++;
    }
    cout << k << " ";
    if (yhi == 100) {
        cout << "inf" << endl;
    } else {
        while ((int) ceil(x) <= yhi) {
            x = f(x);
            k++;
        }
        k--;
        cout << k << endl; 
    }
}
