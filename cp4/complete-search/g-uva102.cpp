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
	int a[9];
	char bins[3] = {'B', 'C', 'G'};
	while (cin >> a[0]) {
		for (int i = 1; i < 9; i++) {
			cin >> a[i];
		}
		
		// make into b,c,g format
		swap(a[1], a[2]);
		swap(a[4], a[5]);
		swap(a[7], a[8]);
		
		int best_moves = 2e9;
		string best_str = "ZZZ";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (j == i) continue;
				for (int k = 0; k < 3; k++) {
					if (k == i || k == j) continue;
					
					int b, c, g;
					int moves = 0;
					
					if (i == 0) b = a[0];
					else if (j == 0) b = a[3];
					else b = a[6];
					
					if (i == 1) c = a[1];
					else if (j == 1) c = a[4];
					else c = a[7];
					
					if (i == 2) g = a[2];
					else if (j == 2) g = a[5];
					else g = a[8];
					
					moves += a[0] + a[3] + a[6] - b;
					moves += a[1] + a[4] + a[7] - c;
					moves += a[2] + a[5] + a[8] - g;
					
					if (moves <= best_moves) {
						string str;
						str += bins[i];
						str += bins[j];
						str += bins[k];
						
						if (moves < best_moves) {
							best_str = str;
						} else {
							best_str = min(best_str, str);	
						}
						
						best_moves = moves;
					}
				}
			}
		}
		cout << best_str << " " << best_moves << endl;
	}
}
