//Leetcode:948
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans = 0;
        int score = 0;
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        int l = 0;
        int r = n-1;
        
        while(r>=l)
        {
            if(power>=tokens[l])
            {
                score += 1;
                power -= tokens[l];
                l++;
                ans=max(ans,score);
            }
            else if(power<tokens[l] && score>0)
            {
                score -= 1;
                power += tokens[r];
                r--;
            }
            else
                return ans;
        }
        return ans;
    }
};