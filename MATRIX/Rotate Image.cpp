//LeetCode:48
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& A) {
        
        int n=A.size();
        for(int i=0;i<n;i++)          //Transpose of Matrix
            for(int j=0;j<i;j++)
                swap(A[i][j],A[j][i]);
        
        for(int i=0;i<n;i++)           //Reverse the Matrix
            reverse(A[i].begin(),A[i].end());
    }
};