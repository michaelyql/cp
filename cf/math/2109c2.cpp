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

int n, res;

void solve() {
	cin >> n;
	
	cout << "mul 9" << endl; cout.flush(); cin >> res;
	cout << "digit" << endl; cout.flush(); cin >> res;
	cout << "digit" << endl; cout.flush(); cin >> res;
	cout << "add " << n - 9 << endl; cout.flush(); cin >> res;
	
	cout << "!" << endl; cout.flush();
	cin >> res;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
