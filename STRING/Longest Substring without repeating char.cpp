//LeetCode:3
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int> mp;            //SLIDING WINDOW APPROACH
        int st=0;
        int end=0;
        int ans=0;
        
        while(end<n)
        {
            mp[s[end]]++;
            while(mp[s[end]] > 1)
            {
                mp[s[st]]--;
                st++;
            }
            ans=max(ans,end-st+1);
            end++;
                
        }
        return ans;
      
        
    }
};