//Leetcode:530
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
    void inorder(TreeNode* root, int& prev, int& ans)
    {
        if(root)
        {
            inorder(root->left,prev, ans);
            
            if(prev != INT_MIN)
            {
                ans = min(ans,abs(root->val-prev));
            }
            
            prev= root->val;
            
            inorder(root->right,prev,ans);
        }
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        
        int prev = INT_MIN;
        int ans = INT_MAX;
        inorder(root,prev,ans);
        return ans;
    }
};