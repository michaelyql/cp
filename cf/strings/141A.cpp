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
    string a, b, c;
    cin >> a >> b >> c;
    if (a.length() + b.length() != c.length()) 
    {
        cout << "NO\n"; 
        return 0;
    }
    int count1[26] {0}, count2[26] {0};
    loop(i, c.length())
    {
        count1[c[i] - 'A']++;
    }
    loop(i, a.length())
    {
        count2[a[i] - 'A']++;
    }
    loop(i, b.length())
    {
        count2[b[i] - 'A']++;
    }
    loop(i, 26)
    {
        if (count1[i] != count2[i]) 
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}
