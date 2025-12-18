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

struct edge {
    int u,v;
    ll d;
    edge(int i, int j, ll dist): u(i), v(j), d(dist) {}
};

struct DSU {
    vector<int> par,sz;
    DSU(int n): par(n), sz(n, 1){
        for(int i=0;i<n;i++) par[i]=i;
    }
    int find(int u){
        return (par[u] == u) ? u : (par[u] = find(par[u]));
    }
    bool unite(int u,int v){
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
        return true;
    }
};

bool ok(ll guess, vector<edge>& edges, int n) {
    DSU dsu(n);
    int cc = n;
    for(auto& e : edges) {
        if(guess >= e.d){
            if (dsu.unite(e.u, e.v)) cc--;
        }
    }
    return cc == 1;
}

void solve() {
    ifstream infile("moocast.in");
    ofstream outfile("moocast.out");
    int n;
    infile >> n;
    vector<pii> pos;
    rep(i,0,n){
        int x,y;
        infile>>x>>y;
        x--,y--;
        pos.push_back({x,y});
    }   
    vector<edge> edges;
    ll maxd = 0;
    rep(i,0,n){
        rep(j,0,n){
            if(i!=j){
                int dx = pos[j].first - pos[i].first;
                int dy = pos[j].second - pos[i].second;
                ll d = 1ll * dx * dx + 1ll * dy * dy;
                edges.push_back({i,j,d});
                maxd = max(maxd, d);
            }
        }
    }
    ll low=0, high=maxd;
    ll ans=1e17;
    // guess the amount X to be paid
    while (low <= high) {
        ll mid=(high+low)/2;
        if (ok(mid, edges, n)) {
            ans=min(ans,mid);
            high=mid-1;
        } else {
            low=mid+1;
        }
    }
    outfile<<ans;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    solve();
    // int t;
    // cin >> t;
    // while (t--) solve();
}
