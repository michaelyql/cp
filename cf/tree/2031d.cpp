#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

struct node {
	int mx;
	int idx;
	node(): mx(0), idx(0) {}
	node(int m, int i): mx(m), idx(i) {}
	bool operator>(const node& other) const {
		return this->mx > other.mx;
	}
};

ostream& operator<<(ostream& os, const node& u) {
	os << "(" << u.mx << ", " << u.idx << ")";
	return os;
}

const int N = 5e5 + 5;
int A[N];

node st[N];

void build(int u, int l, int r) {
	if (l == r) {
		st[u] = node(A[l], l); 
	} else {
		int m = l + (r - l) / 2;
		build(u * 2, l, m);
		build(u * 2 + 1, m + 1, r);
		if (st[u * 2].mx > st[u * 2 + 1].mx) {
			st[u] = st[u * 2];
		} else {
			st[u] = st[u * 2 + 1];
		}
	}
}

node& query(int u, int l, int r, int ql, int qr) {
	// cout << "u: " << u << ", l: " << l << ", r: " << r;
	// cout << ", ql: " << ql << ", qr: " << qr << endl;
	if (ql > qr) {
		return st[0];
	}
	if (l == ql && r == qr) {
		return st[u];
	} else {
		int m = l + (r - l) / 2;
		node& node_left = query(u * 2, l, m, ql, min(qr, m));
		node& node_right = query(u * 2 + 1, m + 1, r, max(ql, m + 1), qr);
		if (node_left > node_right) {
			return node_left;
		} else {
			return node_right;
		}
	}
}

void solve() {
	cout << "\n new tc \n";
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	build(1, 1, n);
	vector<int> ans(n + 1);
	
	vector<pii> v;
	vector<int> rmi(n + 1);
	
	for (int i = n; i >= 1; i--) {
		if (v.size() == 0) {
			v.push_back({A[i], i});	
			rmi[i] = i;
		} else {
			if (A[i] > v[v.size() - 1].first) {
				int l = 0, r = v.size() - 1;
				while (l < r) {
					int mid = l + (r - l) / 2;
					if (v[mid].first < A[i]) {
						r = mid;
					} else {
						l = mid + 1;
					}
				}
				rmi[i] = v[r].second;
			} else if (A[i] < v[v.size() - 1].first) {
				v.push_back({A[i], i});
				rmi[i] = i;
			} else {
				rmi[i] = i;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		cout << "\n---\ni:" << i << ", ";
		cout << "A[" << i << "]: " << A[i] << endl;
		
		node& nl = query(1, 1, n, 1, i - 1);
		cout << "nl: " << nl << endl;
		if (rmi[i] == i) {
			cout << max(A[i], nl.mx) << " "; 
		} else {
			node& nr = query(1, 1, n, i, rmi[i] - 1);
			cout << max(nl.mx, nr.mx) << " ";
			cout << "nr: " << nr << endl;
		}
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
