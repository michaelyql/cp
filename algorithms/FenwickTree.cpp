#include <vector>
#include <iostream>

using namespace std;

void add(int i, int k, vector<int>& T) {
	int n = T.size();
	while (i < n) {
		T[i] += k;
		i += (i & -i);
	}
}

int sumHelper(int i, vector<int>& T) {
	int sum = 0;
	while (i > 0) {
		sum += T[i];
		i -= (i & -i);
	}
	return sum;
}

int sum(int i, int j, vector<int>& T) {
	return sumHelper(j, T) - sumHelper(i - 1, T);
}

void make_tree(vector<int>& a) {
	vector<int> tree(a);
	int n = a.size();
	for (int i = 0; i < n; i++) {
		int p = i + (i & -i); 
		if (p < n) { 
			tree[p] = tree[p] + tree[i];
		}
	}
	std::copy(tree.begin(), tree.end(), a.begin());
}

int main() {
	vector<int> a {0, 4, 8, 5, 2, 6, 1, 0, 8, 1, 5, 4, 9, 1, 0, 6, 6}; // ignore 0th index
	make_tree(a);
	cout << "Tree: ";
	for (int x : a) cout << x << ' ';
	cout << '\n';
	cout << sum(1, 2, a) << '\n';
	cout << sum(2, 7, a) << '\n';
	cout << sum(5, 9, a) << '\n';
	add(4, 10, a);
	cout << sum(2, 7, a) << '\n';
}
