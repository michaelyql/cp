#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

bool isEven(char c) {
	if (c == '0' || c == '2' || c == '4' || c == '6' || c == '8') return true;
	else return false;
}

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<char> evens, odds;
	for (int i = 0; i < s.size(); i++) {
		if (isEven(s[i])) evens.push_back(s[i]);
		else odds.push_back(s[i]); 
	}
	int i = 0, j = 0; 
	vector<char> ans;
	while (i < evens.size() && j < odds.size()) {
		if (evens[i] < odds[j]) {
			ans.push_back(evens[i]);
			i++;
		} else {
			ans.push_back(odds[j]);
			j++;
		}
	}
	if (i != evens.size()) {
		for (; i < evens.size(); i++) ans.push_back(evens[i]);
	}
	if (j != odds.size()) {
		for (; j < odds.size(); j++) ans.push_back(odds[j]);
	}
	
	ostringstream oss;
	for (int i = 0; i < ans.size(); i++) {
		oss << ans[i];
	}
	cout << oss.str() << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
