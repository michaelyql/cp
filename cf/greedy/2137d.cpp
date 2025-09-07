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
    vi b(n);
    rep(i,0,n)cin>>b[i];
    int g=0;
    map<int,array<int, 2>> mp;
    vi a(n);
    for(int i =0;i<n;i++){
        if (mp.find(b[i]) != mp.end()) mp[b[i]][0]--;
        else mp[b[i]] = {b[i]-1,++g};
        a[i] = mp[b[i]][1];
        if (!mp[b[i]][0]) mp.erase(b[i]);
    }
    if(mp.size()) {cout<<-1<<endl; return; }
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
