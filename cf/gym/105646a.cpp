#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

const int N = 1e6 + 7;
vector<pii> adj[N];
int n, m;
int dp[N];



int main() {
  cin.sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v, i});
  }
  
  
  
}
