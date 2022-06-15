//LeetCode:1695
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> set;
        int n=nums.size();
        int currsum=0;
        int i=0;
        int ans=0;
        
        for(int j=0;j<n;j++)
        {
            currsum += nums[j];
            
            while(i<=j && set.find(nums[j])!=set.end())
            {
                currsum=currsum-nums[i];
                set.erase(nums[i]);
                i+=1;
            }
            set.insert(nums[j]);
            ans=max(ans,currsum);
        }
       return ans;
    }
};