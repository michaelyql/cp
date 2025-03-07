#include <iostream>
#include <vector>
#include <string>
#include <cctype>  // tolower, toupper, isalpha, isdigit etc.
#include <algorithm> // transform, count, reverse, fill, sort
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <cstring> // memset
#include <queue>
#include <utility> // pair

#define rep(ii, a, b) for (int ii = a; ii < b; ++ii)
#define repr(ii, a, b) for (int ii = a; ii >= b; --ii)
#define debug_arr(A) for (int ii = 0; ii < A.length(); ii++) cout << A[ii] << ' '; cout << '\n'
#define debug_vec(V) for (int ii = 0; ii < V.size(); ii++) cout << V[ii] << ' '; cout << '\n'
#define mod 998244353

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template<typename T, size_t N, size_t M>
void print_arr2d(T(&array)[N][M]) 
{
    cout << "Matrix: \n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) cout << array[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

int main()
{
    // init
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << -1;
        return 0;
    }

    vector<int> b(n);
    rep(i, 0, n) cin >> b[i];
    string colours;
    cin >> colours;

    // solving
    vector<int> bO(n);
    vector<int> bR(n);
    vector<int> bW(n); 
    rep(i, 0, colours.length()) {
        if (colours[i] == 'R') bR[i] = b[i];
        else if (colours[i] == 'W') bW[i] = b[i];
        else bO[i] = b[i];
    }
    sort(bO.begin(), bO.end(), greater<int>());
    sort(bR.begin(), bR.end(), greater<int>());
    sort(bW.begin(), bW.end(), greater<int>());
    int ans1 {-1};
    int ans2 {-1};

    if (k == n) {
        if (bW[0] != 0 && bR[0] != 0) {
            cout << -1 << '\n';
            return 0;
        }        
    }
    
    // Orange and Red
    if (bO[0] != 0 && bR[0] != 0) {
        ans1 = bO[0] + bR[0];
        int red = 1, orange = 1;
        for (int i = 0; i < k - 2; i++) {
            if (bO[orange] > bR[red]) ans1 += bO[orange++]; 
            else ans1 += bR[red++]; 
        }
    }

    // Orange and White
    if (bW[0] != 0 && bO[0] != 0) {
        ans2 = bW[0] + bO[0];
        int white = 1;
        int orange = 1;
        for (int i = 0; i < k - 2; i++) {
            if (bW[white] > bO[orange]) ans2 += bW[white++]; 
            else ans2 += bO[orange++];
        }
    }

    cout << max(ans1, ans2);
}
