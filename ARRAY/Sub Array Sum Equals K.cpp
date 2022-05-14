//LeetCode:560
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int sum=nums[i];
            if(sum==k)
                ans++;
            for(int j=i+1;j<n;j++)
            {
                sum+=nums[j];
                if(sum==k)
                    ans++;
            }
        }
        return ans;
    }
};

//Optimized Approach using Prefix Sum
//O(n) Time Complexity

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            
            if(sum==k) ans++;
            
            if(mp.find(sum-k)!=mp.end())
                ans=mp[sum-k]+ans;
            
            if(mp.find(sum)!=mp.end())
                mp[sum]++;
            else
                mp[sum]=1;
        }
        return ans;
    }
};