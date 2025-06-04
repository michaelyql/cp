#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
#define LSOne(S) ((S) & -(S)) 
#define all(x) (x).begin(), (x).end()
// #define debug
 
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

using node = pair<int, pii>;

struct comp {
    bool operator() (const node& n1, const node& n2) const {
        return n1.first > n2.first;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    rep(i, 0, n) cin >> grid[i];
    vector<char> ans;
    int i = 0, j = 0;
    vector<vector<bool>> seen(n, vector<bool>(n, false));
    while (i != n - 1 || j != n - 1) {
        ans.push_back(grid[i][j]);
        int right = 100, down = 100;
        if (j + 1 < n) right = grid[i][j + 1] - 'A';
        if (i + 1 < n) down = grid[i + 1][j] - 'A';
        if (right < down) {
            j++;
        } else if (down < right) { 
            i++;
        } else {
            priority_queue<node, vector<node>, comp> pq; // min pq
            if (j + 1 < n) pq.push({ right, {i, j + 1} });
            if (i + 1 < n) pq.push({ down, {i + 1, j} });
            while (!pq.empty()) {
                node u = pq.top();
                pq.pop();
                int sz = pq.size();
                vector<node> next_frontier;
                for (int k = 0; k < sz; k++) {
                    node v = pq.top();
                    pq.pop();
                    if (v.first != u.first) break;
                    int ci = v.second.first, cj = v.second.second;
                    if (cj + 1 < n && !seen[ci][cj + 1]) {
                        next_frontier.push_back({ grid[ci][cj + 1] - 'A', {ci, cj + 1}});
                        seen[ci][cj + 1] = true;
                    }
                    if (ci + 1 < n && !seen[ci + 1][cj]) {
                        next_frontier.push_back({ grid[ci + 1][cj] - 'A', {ci + 1, cj}});
                        seen[ci + 1][cj] = true;
                    }
                }
                if (next_frontier.empty()) {
                    i = u.second.first;
                    j = u.second.second;
                    break;
                }
                ans.push_back(u.first + 'A');
                int ci = u.second.first, cj = u.second.second;
                if (cj + 1 < n && !seen[ci][cj + 1]) next_frontier.push_back({ grid[ci][cj + 1] - 'A', {ci, cj + 1}});
                if (ci + 1 < n && !seen[ci + 1][cj]) next_frontier.push_back({ grid[ci + 1][cj] - 'A', {ci + 1, cj}});
                while (!pq.empty()) pq.pop(); // clear any remaining nodes
                for (auto v: next_frontier) pq.push(v);
            }
        }
    }
    ans.push_back(grid[n - 1][n - 1]);
    string min_string(ans.begin(), ans.end());
    cout << min_string << endl;
}
