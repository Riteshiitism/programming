// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
#include <bits/stdc++.h>
using namespace std;
int search(int arr[], int n, int x, int k)
{
    int i = 0;
    while(i<n){
        if(arr[i]==x) return i;
        int d = abs(x-arr[i]);
        int jump = d/k;
        if(jump>0) i += jump;
        else i++;
    }
    return -1;
}  
int main(){
    int arr[] ={4, 5, 6, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 6;
    int k =1;
    cout<<search(arr,n,x,k);
}