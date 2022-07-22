#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
//Memoization Approach
    int t[101][1001];
    bool Subsetsum(int arr[],int n,int sum)
    {
        if(n==0)
        return false;
        
        if(sum==0)
        return true;
        
        if(t[n][sum]!=-1)
        return t[n][sum];
        
        if(arr[n-1]<=sum)
        return t[n][sum]=Subsetsum(arr,n-1,sum-arr[n-1])||Subsetsum(arr,n-1,sum);
        
        else
        return t[n][sum]=Subsetsum(arr,n-1,sum);
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        memset(t,-1,sizeof(t));
        int sum=0;
        for(int i=0;i<n;i++)
        sum=sum+arr[i];
        
        if(sum%2!=0)
        return false;
        
        else
        return Subsetsum(arr,n,sum/2);
    }
};