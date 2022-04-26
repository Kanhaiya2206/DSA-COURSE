//LeetCode:897
#include<bits/stdc++.h>
using namespace std;
//  Definition for a binary tree node.
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
    TreeNode* tree=new TreeNode(0);
    TreeNode* p = tree;
    
    void inorder(TreeNode* root)
    {
        if(root==NULL){
            return;
        }
        
        inorder(root->left);
        tree->right= new TreeNode(root->val);  
        tree->left=NULL;  
        tree=tree->right;  
        
       inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {

        inorder(root);
        return p->right;
    }
};