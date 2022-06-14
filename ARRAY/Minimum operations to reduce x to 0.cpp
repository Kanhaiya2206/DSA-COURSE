//LeetCode:1658
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        int n=nums.size();
        for(int i:nums)
            sum+=i;
        int currsum=0;
        int maxlen=0;
        int i=0;
        int target = sum-x; bool found=false;
        
        for(int j=0;j<n;j++)
        {
            currsum+=nums[j];
            
            while(i<=j && currsum > target)
            {
                currsum = currsum - nums[i];
                i+=1;
            }
            if(currsum == target)
            {
                found=true;
                maxlen = max(maxlen,j-i+1);
            }
        }
        return found ? n-maxlen: -1;
        
    }
};