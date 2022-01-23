#include<bits/stdc++.h>

using namespace std;

void MaxHeapify(int arr[],int n, int i)
{
    int parent = i;
    int left=2*i;
    int right=2*i+1;

    if(left<=n && arr[left]>arr[parent])
        parent = left;

    if(right<=n && arr[right]>arr[parent])
        parent = right;

    if(parent != i)
    {
       swap(arr[parent],arr[i]);

      MaxHeapify(arr,n,parent);   //Recursion
    }    
}

void BuildHeap(int arr[],int n)
{
    for(int i=floor(n/2);i>=0;i--)
    {
        MaxHeapify(arr,n,i);
    }
}

int main()
{
    int arr[] = { 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
    int n=10;

 
    BuildHeap(arr, n);
 
    cout << "Array representation of Heap is:\n";
 
    for (int i = 0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}