class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> rows;
        for (int i = x; i < x + k; i++) {
            rows.push_back(vector<int>());
            for (int j = y; j < y + k; j++) {
                rows.back().push_back(grid[i][j]); 
            }
        }
        reverse(rows.begin(), rows.end());
        for (int i = 0; i < rows.size(); i++) {
            for (int j = 0; j < rows[i].size(); j++) {
                grid[x + i][y + j] = rows[i][j];
            }
        } 
        return grid;
    }
};
