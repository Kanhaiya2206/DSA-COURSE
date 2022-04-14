//LeetCode:700
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
         if(!root) return NULL;
        
        if(val < root->val){
            return searchBST(root->left,val);
        } else if(val > root->val){
            return searchBST(root->right,val);
        } else {
            return root;
        }
    }
};