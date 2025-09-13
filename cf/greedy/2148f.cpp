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

const int MAX=1e8;

void solve() {
    int n;
    cin >> n;
    vvi a(n);

    int max_len=0;
    priority_queue<pii, vector<pii>, greater<pii>> pq; 
    rep(i,0,n){
        int k;
        cin >> k;
        a[i].resize(k);
        rep(j,0,k)cin>>a[i][j];
        pq.push({a[i][0],i});
        max_len=max(max_len,k);
    }

    int cur_len = 0;

    while (!pq.empty() && cur_len < max_len) {
        int i, v;
        tie(v,i)=pq.top();
        pq.pop();
        if (a[i].size() <= cur_len) continue;

        int min_idx = i;

        while(!pq.empty() && pq.top().first == v) {
            int j, w;
            tie(w, j)=pq.top();
            pq.pop();
            if (a[j].size() <= cur_len) continue;
            if (!lexicographical_compare(a[min_idx].begin() + cur_len, a[min_idx].end(), a[j].begin() + cur_len, a[j].end())) {
                pq.push({MAX, min_idx}); 
                min_idx = j;
            } else {
                pq.push({MAX, j});
            }
        }
        
        for (int j = cur_len; j < a[min_idx].size(); j++) {
            cout << a[min_idx][j] << " ";
        }
        cur_len = a[min_idx].size();

        if (!pq.empty()) {
            int sz = pq.size();
            vector<pii> add;
            while (sz--) {
                auto [w, j]=pq.top();
                pq.pop();
                if (a[j].size()>cur_len) add.push_back({a[j][cur_len],j});
            }
            for(auto& p:add) pq.push(p);
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
