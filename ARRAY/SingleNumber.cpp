//Given a non-empty array of integers nums
//every element appears twice except for one. Find that single one.
#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> nums) {
       unordered_map<int,int> m;//Time:O(n) Space:O(n)
        for(auto i:nums)
            m[i]++;
        for(auto j:m)
            if(j.second==1)
                return j.first;
            return -1;
         
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
    int ans=singleNumber(nums);
    cout<<ans<<endl;
    return 0;
} 
//Better Approach (Time:O(nlogn),Space:O(1))
 
/* int singleNumber(vector<int>& nums) {
       sort(nums.begin(),nums.end());
           for(int i=1;i<nums.size();i+=2)
           {
               if(nums[i]!=nums[i-1])
                   return nums[i-1];
           }
        return nums[nums.size()-1];
         
    }
*/      