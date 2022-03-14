 //Given an integer array nums of length n,
 //you want to create an array ans of length 2n where ans[i] == nums[i], and ans[i + n] == nums[i]
 #include<bits/stdc++.h>

using namespace std;
 
 vector<int> getConcatenation(vector<int> nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<2*n;i++)
            ans.push_back(nums[i%n]);
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
    vector<int> arr= getConcatenation(nums);
    
    for(int i=0;i<n;i++)
       cout<<arr[i]<<" ";
    return 0;
}         
