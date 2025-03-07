#include <iostream>
#include <string>   
#include <stack>

using namespace std;

// Test cases
// (()())()(())()()())())()((()(()(())()()())((()(())()(()()()()))()(())()(((()())()(()((())()(())(())) 28 1
// ))))()()))) 4 1
// ((((()((( 2 1
// ()(())() 8 1

void solve();

int main() {
    string s;
    cin >> s;
    int longest = 0;
    int count = 0;
    int open = 0;
    int length = 0;
    int dp[s.length()];
    for (int i = 0; i < s.length(); i++) dp[i] = -1;

    for (int i = 0; i < s.length(); i++) 
    {
        if (s[i] == '(') 
        {
            open++;
            length = 0;
        } 
        else 
        {
            if (open > 0) 
            {
                open--;
                if (i - 1 > 0 && dp[i - 1] != -1) 
                {
                    length = dp[i - 1] + 2;
                } 
                else if (i - 2 > 0 && dp[i - 2] != -1) 
                {
                    length = dp[i - 2] + 2;
                }
                else {
                    length += 2;
                }

                if (i - length > 0 && dp[i - length] != -1) {
                    length += dp[i - length];
                }

                if (length > longest) 
                {
                    longest = length;
                    count = 1;
                } 
                else if (length == longest) 
                {
                    count++;
                }

                dp[i] = length;
            }
            else 
            {
                length = 0;
            }
        }
    }
    if (longest > 0) cout << longest << " " << count << endl;
    else cout << "0 1" << endl;
    return 0;
}
