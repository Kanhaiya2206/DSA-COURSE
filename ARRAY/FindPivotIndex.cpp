//LeetCode:724
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return -1;
        vector<int> left(n);
        vector<int> right(n);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        
        for(int i=1;i<n;i++)
        {
            left[i]=nums[i]+left[i-1];
            right[n-1-i]=nums[n-1-i]+right[n-i];
        }
        for(int i=0;i<n;i++)
        {
            if(left[i]==right[i]) return i;
        }
        return -1;
        
    }
};