#include <bits/stdc++.h>
using namespace std;
int duplicate(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i])] < 0)
        {
            return abs(arr[i]);
        }
        arr[abs(arr[i])] = -arr[abs(arr[i])];
    }
    return -1;
}
int duplicateBest(int arr[],int n){
    int slow = arr[0];
    int fast = arr[0];
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while (slow!=fast);
    slow = arr[0];
    while (slow!=fast)
    {
        slow=arr[slow];
        fast=arr[fast];
    }
    return slow;
}
int main()
{
    // int arr[] = {1, 3, 4, 2, 2};
    // int arr[] = {2,5,9,6,9,3,8,9,7,1};
    int arr[]={3,1,3,4,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << duplicate(arr, n)<<endl;
    cout<<duplicateBest(arr,n)<<endl;
}