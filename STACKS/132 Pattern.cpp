//LeetCode:456
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
       int n = nums.size();
        int minimum=nums[0];
            for(int j=1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(nums[k]>minimum && nums[j]>nums[k])
                        return true;
                    minimum=min(minimum,nums[j]);
                }
            }
        
        return false;
    }
};
//Better Approach using stack: O(n)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        
        int thirdElement = INT_MIN; //nums[k]
        
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < thirdElement) return true;
            while(!st.empty() && st.top() < nums[i]) {
                thirdElement = st.top();
                st.pop();
            } 
            st.push(nums[i]);
        }
        return false;
    }
};