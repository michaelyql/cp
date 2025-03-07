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
#define debug_arr(A) for (int ii = 0; ii < sizeof(A); ii++) cout << A[ii] << ' '; cout << '\n'
#define debug_vec(V) for (int ii = 0; ii < V.size(); ii++) cout << V[ii] << ' '; cout << '\n'
#define mod 998244353

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template<typename T, size_t N, size_t M>
void print_arr2d(T(&array)[N][M]) 
{
    cout << "Array: \n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) 
        {
            cout << array[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main()
{
    string s, t;
    cin >> s >> t;
    // check if s contains the required characters
    set<int> s1, s2;
    rep(i, 0, t.length()) s1.insert(t[i]);
    rep(i, 0, s.length()) s2.insert(s[i]);
    if (!includes(s2.begin(), s2.end(), s1.begin(), s1.end())) 
    {
        cout << -1 << '\n';
        return 0;
    }
    int arr[26][26] {0};
    rep(i, 0, 26) arr[i][i] = 1;
    rep(i, 0, s.length() - 1)
    {
        int freq = 1;
        int curr = s[i] - 'a';
        rep(j, i + 1, s.length())
        {
            int next = s[j] - 'a';
            if (curr == next) 
            {
                freq++;
                arr[curr][curr] = max(arr[curr][curr], freq);
            }
            else 
            {
                if (j == i + 1)
                {
                    arr[curr][next]++;
                    arr[next][curr]++;
                }
                break;
            }
        }
    }

    

}

/*
aaabrytaaa
ayrat
a + yr + at

3
1 1
6 5
8 7
*/
