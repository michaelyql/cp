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
using pdd = pair<double, double>;

pdd points[4];

double dist(pdd& a, pdd& b) {
	double dx = a.first - b.first;
	double dy = a.second - b.second;
	return dx * dx + dy * dy;
}

int main() {
	const double eps = 1e-8;
	double l, w;
	int n, r;
	cin >> l >> w >> n >> r;
	points[0] = {-l/2, 0};
	points[1] = {l/2, 0};
	points[2] = {0, -w/2};
	points[3] = {0, w/2};
	vector<pdd> cranes(n);
	vector<vector<bool>> cover(n, vb(4));
	rep(i, 0, n) {
		double x, y;
		cin >> x >> y;
		cranes[i] = {x, y};
		for (int p = 0; p < 4; p++) {
			if (dist(cranes[i], points[p]) <= r * r + eps) cover[i][p] = true;
		}
	}
	
	for (int i = 0; i < n; i++) {
		bool ok = true;
		for (int p = 0; p < 4; p++) {
			if (!cover[i][p]) ok = false;
		}
		if (ok) {
			cout << 1 << endl; return 0;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			bool ok = true;
			for (int p = 0; p < 4; p++) {
				if (!cover[j][p] && !cover[i][p]) ok = false;
			}
			if (ok) {
				cout << 2 << endl; return 0;
			}
		}
	}
	
	for (int i = 0; i < n; i++) 
		for (int j = i + 1; j < n; j++) 
			for (int k = j + 1; k < n; k++) {
				bool ok = true;
				for (int p = 0; p < 4; p++) {
					if (!cover[j][p] && !cover[i][p] && !cover[k][p]) ok = false;
				}
				if (ok) {
					cout << 3 << endl; return 0;
				}
			}
			
	for (int i = 0; i < n; i++) 
		for (int j = i + 1; j < n; j++) 
			for (int k = j + 1; k < n; k++) 
				for (int l = k + 1; l < n; l++) {
					bool ok = true;
					for (int p = 0; p < 4; p++) {
						if (!cover[j][p] && !cover[i][p] && !cover[k][p] && !cover[l][p]) ok = false;
					}
					if (ok) {
						cout << 4 << endl; return 0;
					}	
				}
			
	
	cout << "Impossible" << endl;
}
