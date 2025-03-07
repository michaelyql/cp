#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Comp {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        assert(a.size() >= 1);
        return a[1] < b[1];
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Preprocess adjacency matrix
        int n = points.size(); 
        vector<vector<int>> adj(n, vector<int>(n, 0)); 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue; 
                else {
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    adj[i][j] = adj[j][i] = abs(x1 - x2) + abs(y1 - y2); 
                }
            }
        }
        // Prim's
        return 0;
    }
};
