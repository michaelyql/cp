#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
    int res = s1.compare(s2);
    if (res == 0) cout << 0;
    else if (res < 0) cout << -1;
    else cout << 1;
}

unsigned nChoosek( unsigned n, unsigned k )
{
        if (k > n) return 0;
        if (k * 2 > n) k = n-k;
        if (k == 0) return 1;

        int result = n;
        for( int i = 2; i <= k; ++i ) {
                result *= (n-i+1);
                result /= i;
        }
        return result;
}
