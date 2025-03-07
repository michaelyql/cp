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
    int k;
    cin >> k;
    int n = 3;
    int res = 6;
    int temp_k = k * 6;
    while (res < temp_k) 
    {
        res /= (n - 2);
        res *= ++n;
    }
    vector<vector<int>> adj(n, vector<int>(n, 1));
    rep(i, 0, n) adj[i][i] = 0;
    int row = 0;
    int col = 1;
    int cycles = res / 6;
    int count = n - 1; // each node starts with n - 1 edges
    // node should maintain at least 2 edges so it can be part of a cycle
    while (cycles > k) 
    {
        if (count > 2) 
        {
            if (row != col) 
            {
                adj[row][col] = 0;
                adj[col][row] = 0;
                col++;
                count--;
                cycles--;
            }
            else 
            {
                col++;
            }
        } 
        else 
        {
            count = n - 1; // reset to n - 1, move to next node
            row++;
            col = 0;
        }
    }
    cout << n << '\n';
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            cout << adj[i][j];
        }
        cout << '\n';
    }
}
