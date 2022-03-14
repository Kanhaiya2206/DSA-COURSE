//Given a zero-based permutation nums (0-indexed),
// build an array ans of the same length where ans[i] = nums[nums[i]]
#include<bits/stdc++.h>

using namespace std;

vector<int> buildArray(vector<int> nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
            ans.push_back(nums[nums[i]]);
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
    vector<int> arr= buildArray(nums);
    
    for(int i=0;i<n;i++)
       cout<<arr[i]<<" ";
    return 0;
}     