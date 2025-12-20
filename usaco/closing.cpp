#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

random_device rnd;
mt19937 mt(rnd());
// usage: shuffle(all(a), mt)
// usage: uint32_t r = mt()

struct DSU {
	vector<int> par, sz;
	DSU(int n): par(n+1), sz(n+1, 1) {
		for (int i = 1; i <= n; i++) {
			par[i] = i;
		}
	}
	int find(int u) {
		return (par[u] == u) ? u : par[u] = find(par[u]);
	}
	bool unite(int u, int v) {
		int u_parent = find(u);
		int v_parent = find(v);
        if (u_parent == v_parent) return false;
		
		if (sz[u_parent] < sz[v_parent]) swap(u_parent, v_parent);
		sz[u_parent] += sz[v_parent];
		par[v_parent] = u_parent;
		return true;
	}
	bool connected(int u, int v) {
		return find(u) == find(v);
	}
};

void solve() {
    ifstream infile("closing.in");
    ofstream outfile("closing.out");
    int n, m;
    infile >> n >> m;
    vvi adj(n+1);
    rep(i,0,m){
        int u,v;
        infile>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DSU dsu(n);
    vector<bool> ans;
    vector<bool> isopen(n+1,false);
    vector<int> close(n);
    rep(i,0,n){
        infile>>close[i];
    }
    reverse(all(close));

    isopen[close[0]]=true;
    ans.push_back(1);
    int cc=1;
    rep(i,1,n){
        int u=close[i];
        isopen[u]=true;
        cc++;
        for(int v:adj[u]){
            if(isopen[v] && dsu.unite(u,v)) cc--; 
        }
        if(cc==1)ans.push_back(1);
        else ans.push_back(0);
    }
    reverse(all(ans));
    for(auto b:ans) {
        outfile << (b?"YES":"NO")<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    // int t;
    // cin >> t;
    // while (t--) solve();
}
