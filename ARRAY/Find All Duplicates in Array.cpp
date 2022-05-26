//LeetCode:442
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i:nums)
        {
            mp[i]++;
        }
        for(auto x:mp)
        {
            if(x.second>1)
                ans.push_back(x.first);
        }
        return ans;
    }
};