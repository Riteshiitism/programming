#include <bits/stdc++.h>
using namespace std;
int majorityElement(int arr[], int size)
{
    int res = arr[0];
    int cnt = 1;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] == res)
            cnt++;
        else
            cnt--;
        if (cnt == 0)
        {
            res = arr[i];
            cnt = 1;
        }
    }
    cnt = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == res)
            cnt++;
    }
    if (cnt > size / 2)
        return res;
    return -1;
}
int main(){
    int arr[] = {3,1,3,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<arr[majorityElement(arr,n)];
}