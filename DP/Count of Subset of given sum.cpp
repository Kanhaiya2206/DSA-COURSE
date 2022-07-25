#include <bits/stdc++.h>
using namespace std;
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int t[n+1][sum+1];
        int mod=pow(10,9) + 7;
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                t[i][j]=0;
                
                if(j==0)
                t[i][j]=1;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++) //why starting from j=0??
            {
                if(arr[i-1]<=j)
                {
                    t[i][j]=(t[i-1][j-arr[i-1]]+t[i-1][j])%mod;
                }
                else
                {
                    t[i][j]=(t[i-1][j])%mod;
                }
            }
        }
        return t[n][sum];
	}
	  
};



// } Driver Code Ends
/*why do we need to initialize from j=0?
that's where i was stuck, but now the issue got resolved.

Reason is:

the array can have 0 as it's element (which is creating problem here, you remove 0 from all test cases then it'll work fine)

now,  why 0 is creating problem:

if we find, no of subsets of array with sum = 0, then

 -(i) if array doesn't have 0 in it, the ans is simply 1, (i.e. the empty set only)

-(ii) but if array has some entries as 0, then count of subset with sum 0 depends on count of zeros(it'll not be just the empty set).

 

you can test for this example input:

10 31
9 7 0 3 9 8 6 5 7 6

in this test case if you starts from (j = 1) (i.e. you are not handling 0) 
then output will be 37 and when you starts from (j = 0) output will be 40(which is also the correct output for this input) , and 
if you simply change the zero entry to some non zero entry then output will be same no matter (j = 0 ) or (j = 1)*/