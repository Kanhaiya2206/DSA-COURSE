//Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn]
//Return the array in the form [x1,y1,x2,y2,...,xn,yn].LeetCode:1470
#include<bits/stdc++.h>

using namespace std;
vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(nums.size());
        int left=0;
        int right=n;
        int i=0;
        while(left<=n && right<2*n && i<nums.size())
        {
            if(i%2==0)
            {
                ans[i]=nums[left];
                left++;
            }
            else
            {
                ans[i]=nums[right];
                right++;
            }
          i++;
        }
        return ans;
        
        
    }