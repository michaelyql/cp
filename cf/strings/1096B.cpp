#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <cmath>

#define loop(x, n) for (int x = 0; x < n; ++x)
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int MOD = 998244353;

int add(int a, int b) 
{
    return (int)((((ll)a % MOD) + (b % MOD)) % MOD);
}
int mul(int a, int b)
{
    return (int)(((ll)(a % MOD) * (b % MOD)) % MOD);
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[0]) 
        {
            flag = false;
            break;
        }
    }
    if (flag) 
    {
        int m = n + 1;
        if (n % 2 == 0) n /= 2;
        else m /= 2;
        cout << mul(n, m) << endl;
        return 0;
    }
    int left = 1, right = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[0]) break;
        left++;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] != s[n - 1]) break;
        right++;
    }
    int ans = 0;
    if (s[0] == s[n - 1]) ans = mul(right, left);
    ans = add(ans, right);
    ans = add(ans, left);
    ans = add(ans, 1);
    cout << ans << endl;
}
