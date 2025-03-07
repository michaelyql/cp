#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    size_t c = 1;
    size_t n = s.length();
    
    // Assuming that the first letter is R, we read until the next digit character (past C)
    while (c < n && isdigit(s[c])) c++;

    // If the format is indeed RxCy, we read the column number and convert it into radix 26 using the alphabets
    if (c > 1 && c < n) 
    {  
        int col {0}; // col is the numeric value of the column number
        for (size_t i = c + 1; i < n; i++) {
            col = col * 10 + (s[i] - '0'); // Convert the ascii char digit into its numeric value
        }
        int pow {26};

        while (col > pow) {
            col -= pow;
            pow *= 26;
        }
        
        col -= 1;
        while (pow != 1) 
        {
            pow /= 26;
            cout << (char)(col / pow + 'A');
            col %= pow;
        }

        cout << s.substr(1, c - 1) << endl; // Ignore the first character 'R', print substring until 'C'
    }
    /* Otherwise, the original format was the Excel format (e.g. BC23), 
    so we convert it into the RxCy format*/
    else 
    {
        int col{0}, val{0}, pow{1};
        size_t i = 0;
        while (isalpha(s[i]))
        {
            col += pow;
            pow *= 26;
            val = val * 26 + s[i] - 'A';
            i += 1;
        }
        col += val;
        cout << "R" + s.substr(i) + "C" + to_string(col) << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
