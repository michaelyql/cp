#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <set>

#define loop(x, n) for (int x = 0; x < n; ++x)
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

using namespace std;

int main()
{
    int n;
    string s;
    set<char> alph;
    cin >> n >> s;
    loop(i, n)
    {
        if (alph.count(::tolower(s[i])) == 0) alph.insert(::tolower(s[i]));
    }
    if (alph.size() != 26) cout << "NO\n";
    else cout <<"YES\n";
    // set<char>::iterator it;
    // it = alph.begin();
    // for (; it != alph.end(); it++) cout << *it << " ";
}
