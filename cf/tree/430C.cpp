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

int dfs(int curr, int currentLevel, int evenLevelOperations, int oddLevelOperations, vector<int>& init, vector<int>& goal, vector<vector<int>>& adj, vector<int>& res, vector<bool>& vis)
{
    int ans = 0;
    int currentValue = 0;

    if (currentLevel % 2 == 0)
    {
        currentValue = (init[curr] + evenLevelOperations) % 2;
    }
    else 
    {
        currentValue = (init[curr] + oddLevelOperations) % 2;
    }
    
    if (currentValue != goal[curr]) 
    {
        ans += 1;
        res.push_back(curr);

        rep(i, 1, adj[curr].size())
        {
            if (!vis[adj[curr][i]])
            {
                vis[adj[curr][i]] = true;
                if (currentLevel % 2 == 0)
                {
                    ans += dfs(adj[curr][i], currentLevel + 1, evenLevelOperations + 1, oddLevelOperations, init, goal, adj, res, vis);
                }
                else 
                {
                    ans += dfs(adj[curr][i], currentLevel + 1, evenLevelOperations, oddLevelOperations + 1, init, goal, adj, res, vis);
                }
            }
        }
    }
    else 
    {
        rep(i, 1, adj[curr].size())
        {
            if (!vis[adj[curr][i]])
            {
                vis[adj[curr][i]] = true;
                ans += dfs(adj[curr][i], currentLevel + 1, evenLevelOperations, oddLevelOperations, init, goal, adj, res, vis);
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1, vector<int> {0});
    rep(i, 1, n) 
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vector<int> init(n + 1, 0);
    vector<int> goal(n + 1, 0);
    vector<int> res;
    vector<bool> vis(n + 1);
    vis[1] = true;
    rep(i, 1, n + 1)
    {
        cin >> init[i];
    }
    rep(i, 1, n + 1)
    {
        cin >> goal[i];
    }
    cout << dfs(1, 1, 0, 0, init, goal, adj, res, vis) << '\n';
    rep(i, 0, res.size()) cout << res[i] << '\n';
    
}
