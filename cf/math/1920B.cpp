#include <iostream>
#include <vector>
#include <string>
#include <cctype>  // tolower, toupper, isalpha, isdigit etc.
#include <algorithm> // transform, count
#include <set>
#include <cstring> // memset
#include <queue> // pq, queue

#define rep(x, n) for (int x = 0; x < n; ++x)
#define rep1(x, n) for (int x = 1; x < n; ++x)
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

// const int MOD = 998244353;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        int A[n + 1];
        fill(A, A + n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> A[i];
        sort(A + 1, A + n + 1);
        // prefix sum
        for (int i = 1; i <= n; i++) A[i] += A[i-1];
        int ans = -1e9;
        for (int i = 0; i <= k; i++) 
        {
            ans = max(ans, A[n] - 2 * A[min(i + x, n)] + A[i]);
        }
        // for (int i = 0; i <= k; i++) 
        // {
        //     int sum = A[n - i];
        //     for (int j = 0; j < x; j++) 
        //     {
        //         if (n - i - j > 0)
        //             sum -= 2 * (A[n - i - j] - A[n - i - j - 1]);
        //     }
        //     ans = max(ans, sum);
        // }
        cout << ans << "\n";
    }
}
