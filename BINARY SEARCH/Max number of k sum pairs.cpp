//Leetcode:1679
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int a=0;
        int b=nums.size()-1;
        int ans=0;
        
        while(a<b)
        {
            if(nums[a]+nums[b]==k)
            {
                a++; b--; ans++;
            }
            else if(nums[a]+nums[b]>k)
                b--;
            else
                a++;
        }
        return ans;
    }
};