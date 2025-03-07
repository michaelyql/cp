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
    string s;
    cin >> s;
    int c = 1;
    int prev = s[0] - '0';
    for (int i = 1; i < s.length(); i++)
    {
        if (prev == s[i] - '0')
        {
            c++;
        }
        else 
        {
            prev = s[i] - '0';
            c = 1;
        }
        if (c >= 7)
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}
