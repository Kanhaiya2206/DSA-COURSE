
#include<bits/stdc++.h>
using namespace std;
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

