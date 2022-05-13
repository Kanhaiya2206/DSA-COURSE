#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        queue<pair<int,Node*>> q;
        map<int,int> mp;
        
        q.push({0,root});
        
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            
            Node* curr=temp.second;
            int hd = temp.first;
            
            if(mp.find(hd)==mp.end())
            {
                mp[hd]=curr->data;
            }
            if(curr->left)
               q.push({hd-1,curr->left});
            
            if(curr->right)
               q.push({hd+1,curr->right});
            
        }
        for(auto x:mp)
        {
            ans.push_back(x.second);
        }
        return ans;
      
    }

};