#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> v;
      queue<Node*> q;
      
      q.push(root);
      while(!q.empty())
      {
          Node* curr = q.front();
          q.pop();
          v.push_back(curr->data);
          if(curr->right != NULL)
          q.push(curr->right);
          if(curr->left != NULL)
          q.push(curr->left);
      }
      reverse(v.begin(),v.end());
      return v;
}