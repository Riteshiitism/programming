// 1. O(n^2)   and  O(1)    naive approach
// 2. O(n)   and  O(n)    use map
// 3. O(nlogn)   and  O(1)    use sorting and binary search
#include<bits/stdc++.h>
using namespace std;
bool search(int arr[],int s,int e,int x){
    if(s>e) return 0;
    int m = s+(e-s)/2;
    if(arr[m]==x) return 1;
    else if(arr[m]>x)  return search(arr,s,m-1,x);
    else return search(arr,m+1,e,x);
}
bool findPair(int arr[], int size, int d){
    sort(arr,arr+size);
    for(int i = 0; i < size-1; i++){
        if(search(arr,i+1,size-1,arr[i]+d)){
            return 1;
        }
    }
    
    return 0;
}
int main(){
    int arr[] = {5, 20, 3, 2, 5, 80};//70,60,80,40,300
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 78;
    cout<<findPair(arr,n,d);
}