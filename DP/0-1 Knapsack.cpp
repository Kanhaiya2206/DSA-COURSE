
#include<bits/stdc++.h>
using namespace std;
//2. Memoize above recursive code (top-down)
class Solution
{
    public:
    int helper(int w, int wt[], int val[],int n,vector< vector<int>> &t)
    {

        if(n==0 || w==0)
         return 0;
       
       if(t[n][w]!=-1)
         return t[n][w];
         
       if(wt[n-1]<=w)
       {
           return t[n][w]= max(val[n-1] + helper(w-wt[n-1],wt,val,n-1,t) , helper(w,wt,val,n-1,t));
       }
       else if(wt[n-1]>w)
       {
          return t[n][w]= helper(w,wt,val,n-1,t); 
       }
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       vector< vector<int>> t(n+1,vector<int>(w+1,-1));
       
       
       return helper(w,wt,val,n,t);
       
       
      
    }
};

//3. Bottom Up Approach - Dynamic Programming
int knapSack(int w, int wt[], int val[], int n) 
    {
        int t[n+1][w+1];
        
        //Initialize matrix
        for(int i=0; i<w+1; i++)
        for(int j=0; j<n+1; j++)
        {
          if(i==0 || j==0)
            t[i][j]=0;
        }
        
        //Choice Diagram to code
        for(int i = 1; i<n+1; i++){
            for(int j=1; j<w+1; j++){
                //1. In case of choice
                if(wt[i-1] <= j){
                    t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], 0+t[i-1][j]);
                }
                //2. No choice
                else if(wt[i-1] > j){
                    t[i][j] = 0+t[i-1][j];
                }
            }
        }
        return t[n][w];
    }

//1. Recursive Approach
int knapSack(int w, int wt[], int val[], int n) 
    { 
       //Base Case
       if(n==0 || w==0) return 0;
       
        //Choice Diagram Code 
        //1. Choice to include item or not
        if(wt[n-1] <= w){
            return max(val[n-1] + knapSack(w-wt[n-1], wt, val, n-1), 0+knapSack(w,wt,val,n-1));
        }

       //2. No choice
        else if(wt[n-1] > w){
            return 0 + knapSack(w,wt,val,n-1);
        }
   }    
