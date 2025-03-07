#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define loop(x, n) for (int x = 0; x < n; ++x)

int main()
{
    int count[26] {0};
    string s;
    cin >> s;
    int unique = 0;
    loop(i, s.length())
    {
        if (count[s[i] - 'a'] == 0) 
        {
            unique++;
            count[s[i] - 'a']++;
        }
    }
    if (unique % 2 == 0) cout << "CHAT WITH HER!\n";
    else cout << "IGNORE HIM!\n";
}
