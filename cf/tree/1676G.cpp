#include <iostream>
#include <vector>
#include <string>
#include <cctype>  // tolower, toupper, isalpha, isdigit etc.
#include <algorithm> // transform, count, reverse, fill
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
    cout << "Array: \n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) cout << array[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

void solve(int curr, vector<vector<int>>& adj, vector<int>& black, vector<int>& white, int& ans) 
{
    int m = adj[curr].size();
    if (m > 0)
    {
        rep(i, 0, m) // for each child
        {
            solve(adj[curr][i], adj, black, white, ans); // recursively call the solve function
            if (white[adj[curr][i]] == black[adj[curr][i]]) ans++; // if the child's number of white nodes is equal
            // to the child's number of black nodes, increment the answer (we have found a WB-balanced subtree)
        }
        rep(i, 0, m)
        {
            // sum up the number of white and black nodes under the current subtree (including current node)
            black[curr] += black[adj[curr][i]]; 
            white[curr] += white[adj[curr][i]];
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        rep(i, 2, n + 1) 
        {
            int p;
            cin >> p;
            adj[p].push_back(i);
        }
        string s;
        cin >> s;
        vector<int> white(n + 1, 0);
        vector<int> black(n + 1, 0);
        rep(i, 0, n) 
        {
            if (s[i] == 'W') white[i + 1]++;
            else black[i + 1]++;
        }
        int ans = 0;
        solve(1, adj, black, white, ans);
        if (white[1] == black[1]) ans++;
        cout << ans << '\n';
    }
}
