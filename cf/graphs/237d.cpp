#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 10e5 + 10;
vector<int> adj[N];

int main() {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> t(n - 1, vector<int>(2, 0)); // the T-decomp tree, each node is just an edge in E(S)
  unordered_map<int, vector<int>> map;

  // t[i][0] and t[i][1] are the vertices
  // t[i][2] is the 'index' of the node in t
  for (int i = 0; i < n - 1; i++) {
    cin >> t[i][0] >> t[i][1]; 
    map[t[i][0]].push_back(i);
    map[t[i][1]].push_back(i);
  }

  cout << n - 1 << endl;
  for (int i = 0; i < n - 1; i++) {
    cout << "2 " << t[i][0] << " " << t[i][1] << endl; // add 1 to make 1 indexed
  }
  
  vector<vector<int>> edges; // edges of t

  for (size_t i = 1; i <= n; i++) {
    if (map[i].size() > 1) {
      for (size_t j = 0; j < map[i].size() - 1; j++) {
        edges.push_back({ map[i][j] + 1, map[i][j + 1] + 1 });
      }
    }
  }

  for (int i = 0; i < edges.size(); i++) {
    cout << edges[i][0] << " " << edges[i][1] << endl;
  }
}
