
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[100];
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    cout<<"enter array elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int min=arr[0];
    int max=arr[1];
    if(n==1)
    {
        min=arr[0];
        max=arr[1];
    }
    if(arr[0]>arr[1])
    {
        min=arr[1];
        max=arr[0];
    }
    else
    {
        min=arr[0];
        max=arr[1];
    }
    for(int i=2;i<n;i++)
    {
        if(arr[i]>max)
        max=arr[i];
        else if(arr[i]<min)
        min=arr[i];
    }
    cout<<"max element is"<<max<<endl;
    cout<<"min element"<<min<<endl;
}