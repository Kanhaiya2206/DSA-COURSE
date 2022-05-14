//LeetCode:525
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxlen=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int zero=0,ones=0;
            for(int j=i;j<n;j++)
            {
                if(nums[j]==0)
                    zero++;
                else
                    ones++;
                if(zero==ones)
                    maxlen=max(maxlen,j-i +1);
            }
            
        }
        return maxlen;
    }
};

//Optimized Approach using prefix sum
//Time complexity:O(n)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum=0;
        int maxlen=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                nums[i]=-1;
        }
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            
            if(sum==0)
                maxlen=max(maxlen,i+1);
            
            if(mp.find(sum)!=mp.end())
                maxlen=max(maxlen,i-mp[sum]);
            else
                mp[sum]=i;
        }
        return maxlen;
    }
};