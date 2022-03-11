//Find Duplicate in an array of n+1 elements...
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
    //Logic part starts...    
    for(int i=0;i<n;i++)
       arr[arr[i]%n]=arr[arr[i]%n]+n;
    for(int i=0;i<n;i++)
    {
        if(arr[i]/n>1) 
            cout<<i<<endl;
    }
    //Logic Part Ends..
}
int main()
{
    solve();
    return 0;
}