#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5;
ll a[N];
ll bit[N];

int n;

void update(int pos, int change) {
    while (pos <= n) {
        bit[pos] += change;
        pos += pos & -pos;
    }
}

ll query_helper(int pos) {
    ll ret = 0;
    while (pos > 0) {
        ret += bit[pos];
        pos = pos - (pos & -pos);
    }
    return ret;
}

ll query(int l, int r) {
    return query_helper(r) - query_helper(l - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ":" << endl;
        int q;
        cin >> n >> q;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            bit[i] = 0;
        }
        
        for (int i = 1; i <= n; i++) {
            update(i, a[i]);
        }
        
        for (int k = 0; k < q; k++) {
            int type, i, v, j;
            cin >> type;
            if (type == 1) {
                cin >> i;
                i++; // make 1-indexed
                cout << a[i] << endl;
                update(i, -a[i]);
                a[i] = 0;
            } else if (type == 2) {
                cin >> i >> v;
                i++; 
                update(i, v);
                a[i] += v;
            } else {
                cin >> i >> j;
                i++; j++;
                cout << query(i, j) << endl;
            }
        }
        
    }
    
    return 0;
}
