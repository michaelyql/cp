#include <bits/stdc++.h>
// #include "helpers.cpp"
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void dfs(int v, vvi &g, vi &path) {
  for (int u = 0; u < 7; u++) {
    if (g[v][u] > 0) {
      // traverse v->u but also remove u->v
      g[v][u]--;
      g[u][v]--;
      dfs(u, g, path);
    }
  }
  path.insert(path.begin(), v); 
}

struct pair_hash {
public:
  template<class T, class U>
  size_t operator()(const pair<T, U> &p) const {
    return (p.first << 16) ^ p.second;
    // index is not used in the hash, simply for book keeping
  }
};

int main() {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> g(7, vector<int>(7, 0));
  vector<int> in(7, 0);
  unordered_map<pii, vector<int>, pair_hash> dominoes;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    dominoes[{ u, v }].push_back(i + 1);
    in[u]++;
    in[v]++;
    g[u][v]++; // edge between u and v
    g[v][u]++;
  }
  if (n == 1) {
    cout << "1 +";
    return 0;
  }
  int odd_deg_count = 0;
  for (int u = 0; u < 7; u++) {
    if (in[u] & 1) {
      odd_deg_count++;
    }
  }
  if (odd_deg_count != 0 && odd_deg_count != 2) { // 0 for euler cycle, 2 for euler path
    cout << "No solution" << endl;
    return 0;
  }

  // find start node with indegree > 0 and odd indegree
  int start = 0;
  for (int u = 0; u < 7; u++) {
    if (odd_deg_count == 2) {
      if (in[u] & 1) {
        start = u; // For euler cycle, there are 0 nodes with odd degree, so find the first node with in[v] > 0
        break;
      }
    } else {
      if (in[u]) {
        start = u;
        break;
      }
    }
  }

  // dfs to find euler cycle/path
  vector<int> path;
  dfs(start, g, path);

  // after dfs, if an euler cycle or path exists, number of nodes in the answer list should be m + 1
  // where m is the number of dominoes
  
  if (path.size() != n + 1) {
    cout << "No solution" << endl;
    return 0;
  }

  // cout << "Path: " << path;
  // for (auto it = dominoes.begin(); it != dominoes.end(); it++) {
  //   cout << (*it).first << " " << (*it).second << endl;
  // }
  // cout << endl;

  if (path.size() > 1) {
    for (size_t i = 0; i < path.size() - 1; i++) {
      int u = path[i];
      int v = path[i + 1];  
      auto ptr = dominoes.find({ u, v }); // index doesn't matter in the hash here
      if (ptr != dominoes.end()) {

        // (*ptr).second; gives the vector<int> which are the mapped indices of {u, v}
        bool flipped = false;

        if ((*ptr).second.empty()) {
          ptr = dominoes.find({ v, u });
          flipped = true;
        }
      
        cout << *((*ptr).second.begin()) << (flipped ? " -" : " +") << endl;
        (*ptr).second.erase((*ptr).second.begin()); // prone to errors if the vector is empty when erasing

      } else {
        ptr = dominoes.find({ v, u });

        if (ptr != dominoes.end()) {
          cout << *((*ptr).second.begin()) << " -" << endl;
          (*ptr).second.erase((*ptr).second.begin());
        }
      }
    }
  }

  // for (auto it = dominoes.begin(); it != dominoes.end(); it++) {
  //   cout << (*it).first << " " << (*it).second << endl;
  // }
  // cout << endl;
}
