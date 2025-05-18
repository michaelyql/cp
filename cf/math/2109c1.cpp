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

int res, n;

bool solve() {
	cin >> n;

	rep(i, 0, 2) {
		cout << "digit" << endl; cout.flush();
		cin >> res;
	}
	
	cout << "add -8" << endl; cout.flush(); cin >> res;
	cout << "add -4" << endl; cout.flush(); cin >> res;
	cout << "add -2" << endl; cout.flush(); cin >> res;
	cout << "add -1" << endl; cout.flush(); cin >> res;

	cout << "add " << n - 1 << endl;
	cout.flush();
	cin >> res;
	
	cout << "!" << endl;
	cin >> res;
	
	return true;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) {
		if (!solve()) break;
	}
}
