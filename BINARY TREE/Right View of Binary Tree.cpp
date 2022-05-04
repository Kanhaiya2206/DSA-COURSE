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
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       queue<Node*> q;
       
       if(!root) return ans;
       
       q.push(root);
       while(!q.empty())
       {
           int n=q.size();
           ans.push_back(q.front()->data);
           while(n--)
           {
               Node* curr= q.front();
               q.pop();
               if(curr->right) q.push(curr->right);
               if(curr->left) q.push(curr->left);
           }
       }
       return ans;
    }
};
