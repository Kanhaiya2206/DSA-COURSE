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


//Function to return a list containing elements of left view of the binary tre
vector<int> leftView(Node *root)
{
   // Time Complexity: O(n) as all nodes are visited once only
   //Space: O(n)
   //Using level order traversal approach
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
           if(curr->left) q.push(curr->left);
           if(curr->right) q.push(curr->right);
       }
   }
   return ans;
}
