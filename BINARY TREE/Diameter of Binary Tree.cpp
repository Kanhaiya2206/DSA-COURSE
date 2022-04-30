#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int ans=0;
    int height(Node* root){
        // code here 
         if(root==NULL)
            return 0;
         int lh = height(root->left);
         int rh = height(root->right);
         ans = max(ans,1+lh+rh);
    
         return 1+ max(lh,rh);
    }
    int diameter(Node* root) {
        // Your code here
         if(root==NULL)
            return 0;
        height(root);
        return ans;
    }
};
