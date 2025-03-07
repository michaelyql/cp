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
    int upperCount = 0, lowerCount = 0;
    loop(i, s.length())
    {
        if (::isupper(s[i])) upperCount++;
        else lowerCount++;
    }
    if (upperCount > lowerCount) transform(s.begin(), s.end(), s.begin(), ::toupper);
    else transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << endl;
}
