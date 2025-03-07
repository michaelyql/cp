#include <iostream>
#include <vector>
#include <string>
#include <cctype>  // tolower, toupper, isalpha, isdigit etc.
#include <algorithm> // transform, count, reverse, fill, min, max
#include <set>
#include <cstring> // memset
#include <queue>

#define rep(x, n) for (int x = 0; x < n; ++x)
#define rep1(x, n) for (int x = 1; x < n; ++x)
#define repr(x, n) for (int x = n - 1; x >= 0; --x)
#define for1n(x, n) for (int x = 1; x <= n; ++x)
#define debug_arr(A) for (int ii = 0; ii < sizeof(A)/sizeof(*A); ii++) cout << A[ii] << " "; cout << '\n'
#define debug_vec(V) for (int ii = 0; ii < V.size(); ii++) cout << V[ii] << " "; cout << '\n'

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

// const int MOD = 998244353;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int squashed[m];
    fill(squashed, squashed + m, 0);

    int frogs[m];
    rep(i, m) cin >> frogs[i];

    int flies[k];
    rep(i, k) cin >> flies[i];

    rep(i, m)
    {
        rep(j, k)
        {
            if (flies[j] % frogs[i] == 0) squashed[i]++;
        }
    }
    vector<int> smallestFrogs;
    int smallestSquashed = 1e9;
    rep(i, m)
    {
        if (squashed[i] < smallestSquashed)
        {
            smallestFrogs.clear();
            smallestFrogs.push_back(i);
            smallestSquashed = squashed[i];
        }
        else if (squashed[i] == smallestSquashed) smallestFrogs.push_back(i);
    }
    cout << smallestFrogs.size() << '\n';
    rep(i, smallestFrogs.size()) cout << smallestFrogs[i] + 1 << ' ';
    cout << '\n';

    // cout << "DEBUG -----\n";
    // cout << "FROGS: "; 
    // debug_arr(frogs);
    // cout << "FLIES: ";
    // debug_arr(flies);
    // cout << "SQUASHED: ";
    // debug_arr(squashed);
    // cout << "SMALLEST FROGS INDEXES: ";
    // debug_vec(smallestFrogs);
}
