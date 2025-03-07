#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <cstring>

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
        int n;
        cin >> n;
        string a, b, c;
        cin >> a >> b >> c;
        int arr[n];
        memset(arr, 0, n);
        int flag = 0;
        rep(i, n)
        {
            if (a[i] != c[i] && b[i] != c[i]) 
            {
                flag = 1;
                break;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}
