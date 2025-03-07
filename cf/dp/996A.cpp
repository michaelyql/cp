#include <iostream>
#include <vector>
#include <string>
#include <cctype>  // tolower, toupper, isalpha, isdigit etc.
#include <algorithm> // transform, count, reverse, fill
#include <set>
#include <cstring> // memset
#include <queue>

#define rep(x, n) for (int x = 0; x < n; ++x)
#define rep1(x, n) for (int x = 1; x < n; ++x)
#define repr(x, n) for (int x = n - 1; x >= 0; --x)
#define rep1n(x, n) for (int x = 1; x <= n; ++x)
#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define debug_arr(A) for (int ii = 0; ii < A.length(); ii++) cout << A[ii] << ' '; cout << '\n'
#define debug_vec(V) for (int ii = 0; ii < V.size(); ii++) cout << V[ii] << ' '; cout << '\n'

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

// const int MOD = 998244353;

int main()
{
    int n;
    cin >> n;
    int denominations[] = {1, 5, 10, 20, 100};
    int count = 0;
    for (int i = 4; i >= 0; i--)
    {
        while (denominations[i] <= n)
        { 
            n -= denominations[i];
            count++;
        }
    }
    cout << count << endl;
}
