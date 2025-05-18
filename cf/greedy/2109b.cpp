#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
#define LSOne(S) ((S) & -(S)) 
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


int log2_ceil(unsigned int n) {
    
    if ((n & (n - 1)) == 0) {
        return 31 - __builtin_clz(n); 
    }

    return 32 - __builtin_clz(n); 
}


void solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	
	int ans = 1;
	
	int rh = n / 2;
	int ch = m / 2;
	
	int p, q;
	
	if (a <= rh) {
		p = n - a;
	} else {
		p = a - 1;
	}
	
	if (b <= ch) {
		q = m - b;
	} else {
		q = b - 1;
	}
	
	int cut_row = log2_ceil(m) + log2_ceil(n - p);
	int cut_col = log2_ceil(m - q) + log2_ceil(n);
	
	cout << min(cut_row, cut_col) + 1<< endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
