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
    cin >> n;
    int faces = 0;
    loop(i, n)
    {
        string s;
        cin >> s;
        if (s == "Tetrahedron") faces += 4;
        else if (s == "Cube") faces += 6;
        else if (s == "Octahedron") faces += 8;
        else if (s == "Dodecahedron") faces += 12;
        else faces += 20;
    }
    cout << faces << "\n";
}
