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
    cout << "Matrix: \n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) cout << array[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

void dfs(int curr, vector<vector<int>>& adj, vector<bool>& vis, int& ans, vector<int>& path, vector<vector<int>>& paths)
{
    vis[curr] = true;
    path.push_back(curr);
    if (adj[curr].size() > 0)
    {
        dfs(adj[curr][0], adj, vis, ans, path, paths);
    }
    else 
    {
        ans++;
        paths.push_back(path);
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
        int root = 1;
        rep(i, 0, n)
        {
            int p;
            cin >> p;
            if (p == i + 1) root = i + 1;
            else adj[p].push_back(i + 1);
        }
        vector<bool> vis(n + 1);
        int ans = 0;
        queue<int> q;
        vector<vector<int>> paths;
        q.push(root);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            rep(i, 0, adj[curr].size()) q.push(adj[curr][i]);
            if (!vis[curr])
            {
                vector<int> path;
                dfs(curr, adj, vis, ans, path, paths);
            }
        }
        cout << ans << '\n';
        rep(i, 0, paths.size())
        {
            cout << paths[i].size() << '\n';
            rep(j, 0, paths[i].size())
            {
                cout << paths[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';  
    }
}
