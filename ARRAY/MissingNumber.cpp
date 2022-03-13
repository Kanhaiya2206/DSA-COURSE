//Given an array nums containing n distinct numbers in the range [0, n]
//return the only number in the range that is missing from the array.LeetCode:268.
#include<bits/stdc++.h>

using namespace std;

int missingNumber(vector<int> nums) {
       int n=nums.size();
       int sum=(n*(n+1)/2);
        int nums_sum=0;
        for(auto i:nums)
            nums_sum+=i;
        return sum-nums_sum;
        
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
    int ans=missingNumber(nums);
    cout<<ans<<endl;
    return 0;
} 
/*Worst approach
int missingNumber(vector<int> nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size()+1;i++)
            m[i]=0;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        int ans;
        for(int i=0;i<m.size();i++)
            if(m[i]==0)
                ans=i;
        return ans;
        
    }
*/    