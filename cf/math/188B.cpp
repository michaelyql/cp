#include <iostream>
#include <vector>
#include <string>
#include <cctype>  // tolower, toupper, isalpha, isdigit etc.
#include <algorithm> // transform, count
#include <set>
#include <cstring> // memset
#include <queue>

#define rep(x, n) for (int x = 0; x < n; ++x)
#define rep1(x, n) for (int x = 1; x < n; ++x)
#define repr(x, n) for (int x = n - 1; x >= 0; --x)
#define for1n(x, n) for (int x = 1; x <= n; ++x)
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

// const int MOD = 998244353;

int main()
{
    ll a;
    string b;
    cin >> a >> b;
    int k = 0;
    repr(i, b.length()) 
    {
        if (b[k] == '0') continue;
        else break;
    }
    ll bval {0};
    b = b.substr(0, b.length() - k);
    reverse(b.begin(), b.end());
    bval = stoll(b);
    cout << a + bval << endl;
}
