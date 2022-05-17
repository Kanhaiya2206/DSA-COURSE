//LeetCode:1302
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
    int maxdepth(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1+max(maxdepth(root->left),maxdepth(root->right));
    }
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth = maxdepth(root);
        int start=1;
        queue<TreeNode*> q;
        q.push(root);
        while(start<maxDepth)
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                q.pop();
            }
            start++;
        }
        int sum=0;
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            sum+=temp->val;
            q.pop();
        }
        return sum;
    }
};