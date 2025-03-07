#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

#define loop(x, n) for (int x = 0; x < n; ++x)
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int cnt[26] {0};
    loop(i, s.length()) 
    {
        cnt[s[i] - 'a']++;
    }
    int* maxFreq = max_element(cnt, cnt + 26);
    if (*maxFreq > n/2)
    {
        cout << n - (n - *maxFreq) * 2 << endl;
    }
    else 
    {
        cout << n % 2 << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) 
    {
        solve();   
    }
}
