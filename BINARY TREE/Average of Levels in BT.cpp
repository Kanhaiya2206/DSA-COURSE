//Leetcode:637
#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            double temp=0;
            int n=q.size();
            
            for(int i=0;i<n;i++)
            {
               TreeNode* t = q.front();
               q.pop();
            
               if(t->left) q.push(t->left);
               if(t->right) q.push(t->right);
                
                temp += t->val;
            }
            ans.push_back(double(temp/n));
            
        }
        return ans;
    }
};