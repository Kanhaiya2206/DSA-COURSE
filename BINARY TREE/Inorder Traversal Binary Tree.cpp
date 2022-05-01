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
    //ITERATIVE APPROACH
    vector<int> ans;
    void inorderIterative(TreeNode* root)
    {
        stack<TreeNode*> s;
        TreeNode* curr = root;
        
        while(!s.empty() || curr!=NULL)
        {
            if(curr!=NULL)
            {
                s.push(curr);
                curr=curr->left;
            }
            else
            {
                curr=s.top();
                s.pop();
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorderIterative(root);
        return ans;
    }
};
// RECURSIVE APPROACH
class Solution {
public:
    vector<int> ans;
    void inorder(TreeNode* root)
    {
         
        if(root!=NULL)
        {
            inorder(root->left);
            ans.push_back(root->val);
            inorder(root->right);
            
                
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};