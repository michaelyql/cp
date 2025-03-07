#include <bits/stdc++.h>
using namespace std;

/**
 * LC2059: Min Operations to Convert Number
 * 
 * View the problem as finding the shortest path from start to goal, convert to a graph problem
 * Use BFS to find, since each edge is one 'operation' and costs 1, so all edges have the same cost 
 */
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        vector<bool> visited(1001,false);
        q.push(start);
        int ans=0;
        while (!q.empty())
        {
            int size=q.size();
            while (size>0)
            {
                size--;
                int node = q.front();q.pop();
                if (node==goal) return ans;
                if (node<0||node>1000||visited[node]) continue; 
                visited[node]=true;
                for (int i=0;i<nums.size();i++)
                {
                    int a=node+nums[i],b=node-nums[i],c=node^nums[i];
                    for (auto x:{a, b, c}) q.push(x);
                }
            }
            ans++;
        }
        return -1;
    }
};
