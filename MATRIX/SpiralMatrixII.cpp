//LeetCode:59;
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        
        int top,down,left,right;
        top=0;
        down=n-1;
        left=0;
        right=n-1;
        int num=1,i;
        
        while(top<=down && left<=right)
        {
            for(i=left;i<=right;i++)
            {
                ans[top][i]=num++;
            }
            top++;
            for(i=top;i<=down;i++)
            {
                ans[i][right]=num++;
            }
            right--;
            for(i=right;i>=left;i--)
            {
                ans[down][i]=num++;
            }
            down--;
            for(i=down;i>=top;i--)
            {
                ans[i][left]=num++;
            }
            left++;
        }
        return ans;
    }
                
                
                
                
};