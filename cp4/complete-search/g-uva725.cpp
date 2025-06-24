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
	int N;
	bool first = true;
	while (cin >> N && N) {
		if (!first) cout << endl;
		first = false;
		int cnt = 0;
		for (int i = 1234; i <= 99999; i++) {
			if (i * N > 99999) break;
			int x = i * N;
			int y = i;
			vi used(10);
			for (int j = 0; j < 5; j++) {
				used[x % 10]++;
				x /= 10;
			}
			for (int j = 0; j < 5; j++) {
				used[y % 10]++;
				y /= 10;
			}
			bool ok = true;
			for (int j = 0; j <= 9; j++) {
				if (used[j] != 1) ok = false;
			}
			if (ok) {
				cnt++;
				printf("%05d / %05d = %d\n", i * N, i, N); 
			}
		}
		
		/**
		 *  		I Missed A Fullstop. 
		 *
		 **/
		if (!cnt) printf("There are no solutions for %d.\n", N); 
	}
}
