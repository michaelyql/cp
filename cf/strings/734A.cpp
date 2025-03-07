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
    int n;
    string s;
    cin >> n >> s;
    int A = 0, D = 0;
    loop(i, n)
    {
        if (s[i] == 'A') A++;
        else D++;
    }
    if (A > D) cout << "Anton\n";
    else if (A < D) cout << "Danik\n";
    else cout << "Friendship\n";
}
