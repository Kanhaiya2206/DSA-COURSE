#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    void dfs(int node,vector<int> adj[],vector<int>& vis){
        vis[node] = 1;
        for(auto x: adj[node]){
            if(!vis[x]){
                dfs(x,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // Creating Adjacency list as given is adjacency matrix
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
              {
                  cnt++;
                  dfs(i,adj,vis);
              }
        }
        return cnt;
    }
};