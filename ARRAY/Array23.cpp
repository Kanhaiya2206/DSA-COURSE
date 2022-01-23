//MAX SUBARRAY SUM......

#include<bits\stdc++.h>

using namespace std;

int maxproduct(int arr[],int n)
{
    int max_value=arr[0];
    int min_value=arr[0];

    int max_product=arr[0];

    for(int i=1;i<=n;i++)
    {
        if(arr[i]<0)
        swap(max_value,min_value);//When multiplied by -ve number,maxVal becomes minVal,minVal becomes maxVal.
        
        max_value=max(arr[i],max_value*arr[i]);

        min_value=min(arr[i],min_value*arr[i]);

        max_product=max(max_value,max_product);

    }
    return(max_product);
}
int main()
{
    int arr[]={6,-3,-10,0,2};
    int n=5;
    cout<<"maxproduct"<<" "<<maxproduct(arr,n)<<endl;

    return 0;
}