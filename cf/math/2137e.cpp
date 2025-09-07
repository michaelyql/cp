#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define debug

#ifdef debug
#define db(x) cout << #x " = " << x << endl;
#define bp(x) cout << #x << endl;
#else
#define db(x)
#define bp(x)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vb = vector<bool>;
using uint = unsigned int;

random_device rnd;
mt19937 mt(rnd());
// usage: shuffle(all(a), mt)
// usage: uint32_t r = mt()

void solve() {
    int n, k;
    cin >> n >> k;
    int nz = 0;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    for(int i=0;i<n;i++){
        if(a[i]==0)nz++;
    }
    if(nz==0){
        if(k&1)cout<<0<<endl;
        else cout<<n<<endl;
        return;
    }
    if(nz>=2){
        if(k>1){
            if(k&1)cout<<n<<endl;
            else cout<<0<<endl;
            return;
        }
        else {
            vi cnt(n + 1);
            int mex=0;
            for(int i=0;i<n;i++) {
                cnt[a[i]]++;
                while (cnt[mex]) mex++;
            }
            ll ans = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] > mex) ans += mex;
                else {
                    if (cnt[a[i]] == 1) {
                        ans += a[i];                        
                    } else {
                        ans += mex;
                    }
                }
            }
            cout<<ans<<endl;
        }
        return;
    }
    // nz=1
    vi cnt(n + 1);
    int mex=0;
    for(int i=0;i<n;i++) {
        cnt[a[i]]++;
        while (cnt[mex]) mex++;
    }
    ll ans = 0; 

    if (k == 1) {
        for (int i = 0; i < n; i++) {
            if (a[i] > mex) {
                ans += mex;
            } else {
                if (cnt[a[i]] == 1) ans += a[i];
                else ans += mex;
            }
        }
        cout << ans << endl;
        return;
    } else {
        ll ans2 = 0;

        int p = 0;
        while (p < mex) {
            if (cnt[p] > 1) break;
            else p++;
        }
        if (p == mex) {
            int z=0;
            for(int i=0;i<n;i++)if(a[i]>mex)z++;
            for (int i = 0; i < n; i++) {
                if (a[i] > mex) {
                    ans += mex;
                    ans2 += mex;
                    if (z > 1) ans++;
                }
                else {
                    ans += a[i];
                    ans2+=a[i];
                }
            }
        } else {
            for(int i=0;i<n;i++){
                if(a[i]>=p){
                    ans+=p;
                    ans2 +=p+1;
                } else {
                    ans+=a[i];
                    ans2+=a[i];
                }
            }
        }

        if (k % 2 == 0) cout << ans << endl;
        else cout << ans2 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
