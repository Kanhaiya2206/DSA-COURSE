//LeetCode:704
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int BS(vector<int> arr,int i,int j,int x )
    {
        if(i<=j)
        {
            int mid=floor((i+j)/2);
            if(x==arr[mid])
                return mid;
            else
            {
                if(x<arr[mid])
                    return BS(arr,i,mid-1,x);
                else
                    return BS(arr,mid+1,j,x);
            }
        } 
        return -1;
             
    }
    int search(vector<int>& nums, int target) {
        int ans=BS(nums,0,nums.size()-1,target);
        if(ans==-1)
            return -1;
        else 
            return ans;
        
    }
};