#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        
        //KADEN"S ALGORITHM
        int max_sum=INT_MIN;
        int curr_sum=0;
        for(int i=0;i<n;i++)
        {
            curr_sum=curr_sum+arr[i];
            
            if(curr_sum>max_sum)
              max_sum=curr_sum;
            if(curr_sum<0)
              curr_sum=0;
        }
        return max_sum;
        
    }
};


int main()
{
    int t,n;
    
    cin>>t;
    while(t--) 
    {
        
        cin>>n; //input size of array
        
        int a[n];
        cout<<"Enter Array Elements"<<endl;
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends