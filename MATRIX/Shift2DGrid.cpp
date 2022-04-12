//LeetCode:1260
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
         int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        for(int r=0;r<m;r++)
        {
            for(int c=0;c<n;c++)
            {
                int newindex=((r*n + c)+k) % (m*n);
                int newr=newindex/n;
                int newc=newindex%n;
                ans[newr][newc]=grid[r][c];
            }
        }
        return ans;
    }
};