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

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int dfs(int i, int j, ll D, vector<vector<ll>>& A, vector<vector<bool>>& vis, int n) {
    vis[i][j]=true;
    int sz=1;
    for(int k=0;k<4;k++){
        int ni=i+dy[k];
        int nj=j+dx[k];
        if(ni<0||ni>=n||nj<0||nj>=n) continue;
        if(vis[ni][nj])continue;
        if(abs(A[ni][nj]-A[i][j])<=D) {
            sz += dfs(ni,nj,D,A,vis,n);
        }
    }
    return sz;
}

bool ok(ll guess, vector<vector<ll>>& A, int n){
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    int sz=0;
    rep(i,0,n){
        rep(j,0,n){
            if(!vis[i][j]){
                sz=max(sz,dfs(i,j,guess,A,vis,n));
            }
        }
    }    
    return sz>=(n*n+1)/2;
}

void solve() {
    ifstream infile("tractor.in");
    ofstream outfile("tractor.out");
    int n;
    // cin >> n;
    infile >> n;
    ll mn = 1e9, mx = -1e9;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i,0,n)rep(j,0,n){infile>>a[i][j]; mn=min(mn, a[i][j]); mx=max(mx,a[i][j]);}
    ll high=mx-mn,low=0;
    ll ans=0;
    while(low<=high){
        ll mid=(high+low)/2;
        if(ok(mid,a,n)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    // cout<<ans<<endl;
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
