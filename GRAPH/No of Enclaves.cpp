//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid,int delrow[],int delcol[]){
        vis[row][col]=1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,vis,grid,delrow,delcol);
            }
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        //first row
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1)
                dfs(0,j,vis,grid,delrow,delcol);
              //last row  
            if(!vis[n-1][j] && grid[n-1][j]==1)
                dfs(n-1,j,vis,grid,delrow,delcol);        
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1)
                dfs(i,0,vis,grid,delrow,delcol);
                
            if(!vis[i][m-1] && grid[i][m-1]==1)
                dfs(i,m-1,vis,grid,delrow,delcol);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1)
                    cnt++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}


//with BFS


#include <bits/stdc++.h>
using namespace std;




class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
         vector<vector<int>> vis(n,vector<int>(m,0));
         int cnt =0;
         
         
         queue<pair<int,int>>q;
          for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1)
                {q.push({0,j});
                 vis[0][j]=1;}
              //last row  
            if(!vis[n-1][j] && grid[n-1][j]==1)
                {q.push({n-1,j});
                 vis[n-1][j]=1;}        
         }
         for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1)
                {
                    q.push({i,0});
                    vis[i][0]=1;
                }
                
            if(!vis[i][m-1] && grid[i][m-1]==1)
                {
                    q.push({i,m-1});
                    vis[i][m-1]=1;
                }
         }
         while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
         }
             for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1)
                    cnt++;
            }
           }
        
       return cnt;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends