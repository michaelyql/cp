#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

#define loop(x, n) for (int x = 0; x < n; ++x)
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    ::reverse(t.begin(), t.end());
    if (t == s) cout << "YES\n";
    else cout << "NO\n";
}
