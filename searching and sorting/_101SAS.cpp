// use binary search           O(logn)
#include<bits/stdc++.h>
using namespace std;
int firstOccRec(int arr[], int low, int high, int k){
    if (low>high)
    {
        return -1;
    }
    int mid = low + (high-low)/2;
    if (arr[mid]==k)
    {
        if (mid-1>=low && arr[mid-1]==k)
        {
            return firstOccRec(arr,low,mid-1,k);
        }
        else
        {
            return mid;
        }
        
    }
    else if (arr[mid]>k)
    {
        return firstOccRec(arr,low,mid-1,k);
    }
    else
    {
        return firstOccRec(arr,mid+1,high,k);
    }
    
}
int lastOccRec(int arr[], int low, int high, int k){
    if (low>high)
    {
        return -1;
    }
    int mid = low + (high-low)/2;
    if (arr[mid]==k)
    {
        if (mid+1<=high && arr[mid+1]==k)
        {
            return lastOccRec(arr,mid+1,high,k);
        }
        else
        {
            return mid;
        }
        
    }
    else if (arr[mid]>k)
    {
        return lastOccRec(arr,low,mid-1,k);
    }
    else
    {
        return lastOccRec(arr,mid+1,high,k);
    }
    
}
int main(){
    int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};//70,60,80,40,300
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<firstOccRec(arr,0,n-1,5)<<endl;
    cout<<lastOccRec(arr,0,n-1,5)<<endl;
}