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
    int n;
    cin >> n;
    vector<array<ll, 2>> a(n);
    ll s=0;
    rep(i,0,n){ 
        cin>>a[i][0]>>a[i][1];
        s+=a[i][1]-a[i][0];
    }
    sort(a.begin(),a.end(),[](const array<ll,2>& i1, const array<ll,2>& i2) {
        return i1[0]+i1[1] < i2[0]+i2[1];
    });
    ll w = 0;
    rep(i,0,n)w+=a[i][1];
    rep(i,0,n/2)w-=a[i][0]+a[i][1];
    if(n&1){
        w-=a[n/2][0]+a[n/2][1];
        ll k=0;
        rep(i,0,n/2+1)k=max(k,w+a[i][0]);
        w+=a[n/2][0]+a[n/2][1];
        rep(i,n/2+1,n)k=max(k,w-a[i][1]);
        s=s+k;
    } else { s += w; }
    cout <<s<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
