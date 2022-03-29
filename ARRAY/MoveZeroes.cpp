//LeetCode:283
//Time:O(n) Space:O(n)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
                ans.push_back(nums[i]);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                count++;
        }
        while(count--)
            ans.push_back(0);
        for(int i=0;i<n;i++)
            nums[i]=ans[i];
        
    }
};
/*Better Approach Time:O(n) Space:O(1)

void moveZeroes(vector<int>& nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}
*/