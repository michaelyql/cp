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
    set<string> ans;
    vector<pair<int, int>> brackets;
    int n = s.size();
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') st.push(i);
        else if (s[i] == ')') {
            brackets.push_back({st.top(), i});
            st.pop();
        }
    }
    int k = brackets.size();
    for (int mask = 1; mask < (1 << k); mask++) {
        string t = s;
        for (int j = 0; j < k; j++) {
            if (mask & (1 << j)) {
                t[brackets[j].first] = t[brackets[j].second] = ' ';
            }
        }
        t.erase(remove(t.begin(), t.end(), ' '), t.end());
        ans.insert(t);
    }
    for (auto& a: ans) {
        cout << a << endl;
    }
}
