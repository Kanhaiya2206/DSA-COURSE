//LeetCode:56
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       int n=intervals.size();
        if(n<=1)
            return intervals;
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        
        for(int i=1;i<n;i++)
        {
            if(output.back()[1]>=intervals[i][0])
                output.back()[1]=max(output.back()[1],intervals[i][1]);
            
            else
                output.push_back(intervals[i]);
        }
        return output;
    }
};