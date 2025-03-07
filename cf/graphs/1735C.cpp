#include <iostream>
#include <vector>
#include <string>
#include <cctype>  // tolower, toupper, isalpha, isdigit etc.
#include <algorithm> // transform, count, reverse, fill
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <cstring> // memset
#include <queue>
#include <utility> // pair

#define rep(ii, a, b) for (int ii = a; ii < b; ++ii)
#define repr(ii, a, b) for (int ii = a; ii >= b; --ii)
#define debug_arr(A) for (int ii = 0; ii < A.length(); ii++) cout << A[ii] << ' '; cout << '\n'
#define debug_vec(V) for (int ii = 0; ii < V.size(); ii++) cout << V[ii] << ' '; cout << '\n'
#define mod 998244353

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template<typename T, size_t N, size_t M>
void print_arr2d(T(&array)[N][M]) 
{
    cout << "Matrix: \n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) cout << array[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        string t;
        cin >> t;
        set<char> available;
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        char assignment[26] = {0};
        set<char>::iterator it = available.begin();
        rep(i, 0, t.length())
        {
            if (assignment[t[i] - 'a'] != 0)  // if current character has an assignment
            {
                cout << "t[i]: " << t[i] << '\n';
                t[i] = assignment[t[i] - 'a']; 
            }
            else 
            {
                cout << "debug "<< '\n';
                set<char>::iterator nextLowestAvail = it;
                // while ((*nextLowestAvail) == t[i]) 
                rep(j, 0, 26)
                {
                    cout << "finding next lowest avail : " << *nextLowestAvail << '\n';
                    nextLowestAvail++;
                }
                cout << "next lowest avail : " << *nextLowestAvail << '\n';
                if (it == nextLowestAvail) it++;
                assignment[t[i] - 'a'] = t[i] = *nextLowestAvail;
                available.erase(*nextLowestAvail);
            }
        }
        cout << t << '\n';
    }   
}
