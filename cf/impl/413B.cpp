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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> employees[n + 1];
    int messages[m + 1];
    int received[n + 1];
    fill(messages, messages + m + 1, 0);
    fill(received, received + n + 1, 0);
    rep1n(i, n)
    {
        rep1n(j, m)
        {
            int x {0};
            cin >> x;
            if (x == 1) employees[i].push_back(j);
        }
    }
    rep(i, k)
    {
        int emp, grp;
        cin >> emp >> grp;
        messages[grp]++;
        received[emp]--;
    }
    rep1n(i, n) 
    {
        rep(j, employees[i].size())
        {
            received[i] += messages[employees[i][j]];
        }
        cout << received[i] << " ";
    }
    cout << '\n';
}
