#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int bit[N][N];
bool pts[N][N];

void update(int x, int y) {
    // already contain the point
    if (pts[x][y]) return;
    
    pts[x][y] = true;
    
    for (; x <= 1001; x += x & -x) {
        int y1 = y;
        for (; y1 <= 1001; y1 += y1 & -y1) {
            bit[x][y1] += 1;
        }
    }
}

int query(int x, int y) {
    int res = 0;
    for (; x > 0; x -= x & -x) {
        int y1 = y;
        for (; y1 > 0; y1 -= y1 & -y1) {
            res += bit[x][y1];
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ":" << endl;
        
        // reset tree
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < N; j++) {
                bit[i][j] = 0;
                pts[i][j] = false;
            }
        }
        
        int q;
        cin >> q;
        while (q--) {
            int type;
            cin >> type;
            if (type == 0) {
                int x, y;
                cin >> x >> y;
                x++; y++;
                update(x, y);
            } else {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                x1++, y1++, x2++, y2++;
                int res = query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
                cout << res << endl;
            }
        }
    }
    return 0;
}
