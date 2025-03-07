#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

#define rep(x, n) for (int x = 0; x < n; ++x)
#define rrep(x, n) for (int x = n - 1; x >= 0; --x)
#define rep1(x, n) for (int x = 1; x < n; ++x)
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

// const int MOD = 998244353;

void solve() 
{
    int n;
    string s;
    cin >> n >> s;
    int k = s.find_first_of('1');
    k++;
    // check if strictly increasing
    int si = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] < s[i - 1]) si = 0;
    }
    if (si)
    {
        cout << s << endl;
        return;
    }
    rep(i, n)
    {
        if (s[i] != '0') break;
        else cout << '0';
    }
    cout << '0';
    rrep(i, n)
    {
        if (s[i] != '1') break;
        else cout << '1';
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) solve();
}
