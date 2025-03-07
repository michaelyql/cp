#include <iostream>
#include <string>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int x = 0;
    int y = 0;
    pair<int, int> lastMove;
    set<pair<int, int>> positions;
    set<pair<int, int>> neighbourCells;
    pair<int, int> up = {x, y + 1};
    pair<int, int> down = {x, y - 1};
    pair<int, int> left = {x - 1, y};
    pair<int, int> right = {x + 1, y};
    positions.insert({0, 0});
    for (char c: s) 
    {
        lastMove = {x, y};
        if (c == 'U') y++;
        else if (c == 'D') y--;
        else if (c == 'R') x++;
        else x--;
        if (positions.count({x, y}) != 0) // if current move was already passed over
        {
            cout << "BUG" << endl;
            return 0;
        } 
        else 
        {
            positions.insert({x, y});
        }
        up = {x, y + 1};
        down = {x, y - 1};
        left = {x - 1, y};
        right = {x + 1, y};
        neighbourCells.insert(up);
        neighbourCells.insert(down);
        neighbourCells.insert(left);
        neighbourCells.insert(right);
        neighbourCells.erase(lastMove);
        for (auto it = neighbourCells.begin(); it != neighbourCells.end(); it++)
        {
            if (positions.count((*it)) != 0) 
            {
                cout << "BUG" << endl;
                return 0;
            }
        }
        neighbourCells.erase(up);
        neighbourCells.erase(down);
        neighbourCells.erase(left);
        neighbourCells.erase(right);
    }
    cout << "OK" << endl;
    return 0;
}
