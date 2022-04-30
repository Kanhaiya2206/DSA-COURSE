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

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* root){
        // code here 
         if(root==NULL)
    return 0;
    
    return 1+ max(height(root->left),height(root->right));
    }
};
