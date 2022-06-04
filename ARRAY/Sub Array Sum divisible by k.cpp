//LeetCode:974
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        int sum=0;
        int n=nums.size();
        mp[0]=1;// this is done because initial cumulative sum = 0 and that sum%k will be equal to 0 always
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            
            if(rem<0)
                rem+=k;
            if(mp.find(rem)!=mp.end())
                ans+=mp[rem];
            mp[rem]++;
        }
        return ans;

    }
};