//LeetCode:1423
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int> SUM(n,0);
        int sum =0;
        for(int i=0;i<n;i++)
        {
            sum+=cardPoints[i];//Total Sum.
            SUM[i]=sum;
        }
        if(n==k)
            return sum;
        int ans=0;//Sum of subarray that we are going to remove
        int score=0;
        //Making Sliding Window of Subarray each time.
        for(int i=0;i<=k;i++)
        {
            int j = i + (n-k-1);
            if(i==0)
                ans=SUM[j];
            else
                ans = SUM[j] - SUM[i-1];
            score = max(score,sum-ans);
            
        }
        return score;
      
    }
};