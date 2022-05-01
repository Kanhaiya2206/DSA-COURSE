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
 
//ITERATIVE APPROACH 
class Solution {
public:
    vector<int> ans;
    void preorderIterative(TreeNode* root)
    { 
        if(root==NULL)
            return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            
            if(curr->right)
                s.push(curr->right);
            if(curr->left)
                s.push(curr->left);
        }
       
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorderIterative(root);
        
        return ans;
    }
};
//RECURSIVE APPROACH
class Solution {
public:
    vector<int> ans;
    void preorder(TreeNode* root)
    { 
        if(root)
        {
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        
        return ans;
    }
};