#include <bits/stdc++.h>
using namespace std;

const int N = 102;
int A[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(A, 0, sizeof(A));
        int n;
        cin >> n;
        for (int i = 0; i < 3 * n; i++) {
            int x;
            cin >> x;
            A[x]++;
        }
        int sum = 0;
        int cnt = 0;
        for (int i = 1; i <= 100; i++) {
            if (cnt < n) {
                int diff = n - cnt;
                cnt += A[i];
                if (A[i] > diff) {
                    sum += (A[i] - diff) * i;
                }
            } else { 
                if (cnt >= 2 * n) break;
                int diff = 2 * n - cnt;
                cnt += A[i];
                if (A[i] > diff) {
                    sum += diff * i;
                } else {
                    sum += A[i] * i;
                }
            }
            
        }
        cout << sum << endl;
    }
}
