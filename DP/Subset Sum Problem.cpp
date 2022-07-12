
#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    bool subset(vector<int>arr, int sum)
    {

        int n=arr.size();
        int t[n+1][sum+1];
        
        //Initialize Matrix
        for(int i=0;i<n+1;i++)
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            t[i][j]=false;
            
            if(j==0)
            t[i][j]=true;
        }
        for(int i = 1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(arr[i-1]<=j)
                {
                    t[i][j]= (t[i-1][j-arr[i-1]] || t[i-1][j]);
                }
                else
                {
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        return subset(arr,sum);
    }
};


