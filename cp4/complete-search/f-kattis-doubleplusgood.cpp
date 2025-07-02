#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define LSOne(S) ((S) & -(S))
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

int main() {
    string s;
    cin >> s;
    vector<string> v;
    int n = s.size();
    int pos = 0, len = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') {
            v.push_back(s.substr(pos, len));
            pos = i + 1;
            len = 0;
        } else {
            len++;
        }
    }
    v.push_back(s.substr(pos, len)); // last one
    int k = v.size() - 1; // number of + symbols
    unordered_set<ll> ans;
    for (int mask = 0; mask < (1 << k); mask++) {
        vector<string> res;
        res.push_back(v[0]);
        for (int j = 0; j < k; j++) {
            if (mask & (1 << j)) { // concat
                res[res.size() - 1] = res.back() + v[j + 1];
            } else {
                res.push_back(v[j + 1]);
            }
        }
        ll tot = 0;
        for (auto& i: res) {
            tot += stoll(i);
        }
        ans.insert(tot);
    }
    cout << ans.size() << endl;
}
