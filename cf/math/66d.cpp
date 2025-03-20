#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int n;
	cin >> n;
	if (n == 2) {
		cout << -1 << endl;
		return 0;
	}
	cout << 15 << endl;
	cout << 10 << endl;
	cout << 6 << endl;
	for (int i = 4; i <= n; i++) {
		cout << 6 * (i-2) << endl;
	}
}
