//LeetCode:11
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int area=0; int mx=0;
        
        while(i<j)
        {
            int h = min(height[i],height[j]);
            area = h * (j-i);
            if(area > mx)
                mx=area;
            if(height[i] <= height[j])
               i++;
            else
                j--;
        }
        return mx;
        
    }
};