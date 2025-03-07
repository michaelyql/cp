#include <iostream>
#include <vector>
#include <string>
#include <cctype> // tolower, toupper, isalpha etc.
#include <algorithm>
#include <set>

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
        int lowerbound = 1, upperbound = 1e9;
        set<int> neq;
        while (n--)
        {
            int a, x;
            cin >> a >> x;
            if (a == 1) lowerbound = max(lowerbound, x);
            else if (a == 2) upperbound = min(upperbound, x);
            else if (a == 3) 
            {
                neq.insert(x);
            }
        }
        if (lowerbound > upperbound) 
        {
            cout << 0 << '\n';
            continue;
        }
        int ans = upperbound - lowerbound + 1;
        for (set<int>::iterator it = neq.lower_bound(lowerbound); it != neq.upper_bound(upperbound); it++)
        {
            ans--;
        }
        cout << ans << '\n';
    }   
}
