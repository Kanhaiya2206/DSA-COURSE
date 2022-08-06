
#include <bits/stdc++.h>
using namespace std;
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int Range=0;
	    for(int i=0;i<n;i++)
	    {
	        Range=Range+arr[i];
	    }
	    bool t[n+1][Range+1];
	    for(int i=0;i<n+1;i++)
	    for(int j=0;j<Range+1;j++)
	    {
	        if(i==0)
	        t[i][j]=false;
	        
	        if(j==0)
	        t[i][j]=true;
	    }
	    for(int i=1;i<n+1;i++)
	    for(int j=1;j<Range+1;j++)
	    {
	        if(arr[i-1]<=j)
	        t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
	        
	        else
	        t[i][j]=t[i-1][j];
	    }
	    int diff=INT_MAX;
	    for(int j=Range/2;j>=0;j--)
	    {
	        if(t[n][j]==true)
	        diff=min(diff,Range-2*j);
	    }
	    return diff;
	} 
};


