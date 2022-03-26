//LeetCode:121
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int min_price=INT_MAX;//min price till now
        int profit=0;
        for(int i=0;i<n;i++)
        {
            min_price=min(prices[i],min_price);
            profit=max(profit,prices[i]-min_price);
        }
        return profit;
    }
};