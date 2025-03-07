#include <iostream>
#include <string>

using namespace std;

bool checkRow(string s) // check if all black
{
    for (int i = 0; i < 8; i++)
    {
        if (s[i] == 'W') return false;
    }
    return true;
}
bool checkCol(string (&board)[8], int idx) 
{
    for (int i = 0; i < 8; i++) 
    {
        if (board[i][idx] == 'W') return false;
    }
    return true;
}

int main() {
    string board[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> board[i];
    }
    int rowCount = 0;
    // for each row from left to right
    for (int i = 0; i < 8; i++) 
    {
        if (checkRow(board[i])) rowCount++;
    }
    int colCount = 0;
    for (int j = 0; j < 8; j++) 
    {
        if (checkCol(board, j)) colCount++;
    }
    if (rowCount + colCount == 16) cout << 8;
    else cout << rowCount + colCount; 
    cout << endl;
    return 0;
}
