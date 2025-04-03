#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 5e5 + 5;
int cnt[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int n, x;
	cin >> n >> x;
	vi a(n);
	rep(i, 0, n) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	rep(i, 1, x) {
		if (cnt[i] >= i + 1) {
			int j = cnt[i] / (i + 1);
			cnt[i] -= j * (i + 1);
			cnt[i + 1] += j;
		}
		if (cnt[i] != 0) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	
}
