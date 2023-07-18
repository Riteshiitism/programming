#include <bits/stdc++.h>
using namespace std;
vector<int> valueEqualToIndex(int arr[], int n)
{
    vector<int> ans;
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] == i + 1)
            ans.push_back(arr[i]);
    }
    return ans;
}
int main(){
    int arr[] = {15, 2, 45, 12, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans = valueEqualToIndex(arr,n);
    for(int val:ans){
        cout<<val<<" ";
    }
}