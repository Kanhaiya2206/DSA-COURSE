#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {

        sort(arr,arr+n);
        int a=arr[0];
        int b=arr[n-1];
        int diff=b-a;
        int max_val,min_val;
        int x,y;
        
        for(int i=1;i<=n-1;i++)
        {
            y=arr[i];
            x=arr[i-1];
            
            if(y-k>=0)
            {
                max_val=max(x+k,b-k);
                min_val=min(y-k,a+k);
                diff=min(diff,max_val-min_val);
            }
        }
        return diff;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  