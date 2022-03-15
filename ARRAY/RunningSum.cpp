//Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i])
//LeetCode:1480
#include<bits/stdc++.h>

using namespace std;

vector<int> runningSum(vector<int> nums) {
        int n=nums.size();
        vector<int> ans(n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            ans[i]=sum+nums[i];
            sum=sum+nums[i];
        }
        return ans;
    }
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
      cin>>nums[i];
    }
    vector<int> res;
     res=runningSum(nums);
     for(int i=0;i<n;i++)
       cout<<res[i]<<" ";
    return 0;
    
}     