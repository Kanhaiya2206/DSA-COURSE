//LeetCode:977
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       int n=nums.size();
        int s=0;
        int e=nums.size()-1;
        vector<int>res(n);
        int m=n-1;
        while(s<=e){
            if(abs(nums[s]) > abs(nums[e])){
                res[m--]=nums[s]*nums[s];
                s++;
            }
            else{
                res[m--]=nums[e]*nums[e];
                e--;
            }
        }
        return res;
    }
};