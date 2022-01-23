#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int t;
    cout<<"enter no of test cases"<<endl;
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"enter size of array"<<endl;
        cin>>n;
        int arr[n];
        cout<<"enter array elements"<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int k;
        cout<<"enter the kth element"<<endl;
        cin>>k;
        sort(arr,arr+n);
        cout<<arr[k-1];
    }
    return 0;
}