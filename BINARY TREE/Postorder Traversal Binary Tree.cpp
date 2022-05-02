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
 
 //RECURSIVE APPROACH
class Solution {
public:
    vector<int> ans;
    void postorder(TreeNode* root)
    {
        if(root==NULL) return;
        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->val);
        
        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }
};
//ITERATIVE APPROACH
class Solution {
public:
    vector<int> ans;
    void postorder(TreeNode* root)
    {
        if(root==NULL) return;
        stack<TreeNode*> s1;
        s1.push(root);
        stack<int> s2;
        
        while(!s1.empty())
        {
            TreeNode* curr=s1.top();
            s1.pop();
            s2.push(curr->val);
            
            if(curr->left)
                s1.push(curr->left);
            if(curr->right)
                s1.push(curr->right);
                
        }
        while(!s2.empty())
        {
            int t=s2.top();
            s2.pop();
            ans.push_back(t);
        }
        
        
        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }
};