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
	int n;
	cin >> n;
	vi delta(1002);
	rep(i, 0, n) {
		int a, b;
		cin >> a >> b;
		delta[a]++;
		delta[b + 1]--;
	}
	vi cover(1001);
	int cur = 0;
	rep(i, 0, 1001) {
		cur += delta[i];
		cover[i] = cur;
		if (cover[i] == n) {
			cout << "gunilla has a point" << endl;
			return 0;
		}
	}
	cout << "edward is right" << endl;
	
}
