#include <vector>
#include <iostream>

using namespace std;

void update(int i, int k, vector<int>& T) {
	int n = T.size();
	while (i < n) {
		T[i] = min(T[i], k);
		i += (i & -i);
	}
}

int findMin(int i, int j, vector<int>& T) {
	int res = T[j];
    while (j >= i) {
        res = min(res, T[j]);
        j -= (j & -j);
    }
    return res;
}

void make_tree(vector<int>& a) {
	vector<int> tree(a);
	int n = a.size();
	for (int i = 0; i < n; i++) {
		int p = i + (i & -i); 
		if (p < n) { 
			tree[p] = min(tree[p], tree[i]);
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
    cout << findMin(1, 2, a) << '\n';
    cout << findMin(2, 7, a) << '\n';
    cout << findMin(5, 9, a) << '\n';
    update(4, -1, a);
    cout << findMin(2, 7, a) << '\n';
}
