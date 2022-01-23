#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doIntersection(int a[], int n, int b[], int m)  {
        //code here
        int i=0;
        int j=0;
        int count=0;
        while(i<n && j<m)
        {
            if(a[i]<b[j])
              i++;
            else if(a[i]>b[j])
               j++;
            else
            {
                cout<<a[i]<<endl;
                i++;
                j++;
                count++;
                
            }
        }
        return count;
        
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   cout<<"input fot 1 array"<<endl;
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	   cout<<"input for 2 array"<<endl;    
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doIntersection(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends