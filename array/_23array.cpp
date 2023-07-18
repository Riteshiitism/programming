#include <bits/stdc++.h>
using namespace std;
long long maxProduct(int arr[], int n)
{
    long long maxL = INT_MIN;
    long long curr = 1;
    for (int i = 0; i < n; i++)
    {
        curr = curr*arr[i];
        maxL=max(maxL,curr);
        if (arr[i]==0)
        {
            curr=1;
        }
    }
    cout<<maxL<<endl;
    long long maxR=INT_MIN;
    curr=1;
    for (int i = n-1; i >= 0; i--)
    {
        curr = curr*arr[i];
        maxR=max(maxR,curr);
        if (arr[i]==0)
        {
            curr=1;
        }
    }
    cout<<maxR<<endl;
    return max(maxL,maxR);
}
int main(){
    int arr[] = {-4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<maxProduct(arr,n);
}