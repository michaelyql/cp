#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

#define loop(x, n) for (int x = 0; x < n; ++x)
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int MOD = 998244353;

void solve() 
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == s[1]) 
    {
        cout << s[0] << s[0] << endl;
        return;
    }
    else 
    {
        int k = 0;
        while (k < n - 1)
        {
            if (s[k+1] <= s[k]) k++;
            else break;
        }
        s = s.substr(0, k+1);
        cout << s;
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) solve();
}
