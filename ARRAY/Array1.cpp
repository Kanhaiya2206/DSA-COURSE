#include<bits/stdc++.h>

using namespace std;



    
int main()
{
    int n;
    int arr[100];
    
    int temp;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    cout<<"enter array elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    int start=0;
    int end=n-1;
    
    
    while (start<end)
    {
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;

    }
    cout<<"reversed array"<<endl;
    for(int j=0;j<n;j++)
    {
        cout<<arr[j]<<endl;
    }
return 0;    
    
   
}