#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int> &arr, int s, int e)
{
    int mid = (s + e) / 2;
    for (int i = s; i <= mid; i++)
    {
        swap(arr[i], arr[e - i + s]);
    }
}
void nextPermutation(vector<int> &arr)
{
    int n = arr.size();
    bool chk = true;
    int idx = -1;
    for (int i = n - 1; i > 0; i--)  // find declination
    {
        if (arr[i - 1] < arr[i])
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        reverse(arr, 0, n - 1);
        return;
    }
    int just_greater = idx;
    for (int i = idx + 1; i < n; i++)   // find just greater than arr[idx-1]
    {
        if (arr[i] > arr[idx - 1] && arr[i] <= arr[just_greater])
        {
            just_greater = i;
        }
    }

    swap(arr[idx - 1], arr[just_greater]);  //swap  them
    reverse(arr, idx, n - 1);               // reverse 

    return;
}
int main()
{
    vector<int> arr = {2,3,1,3,3};
    nextPermutation(arr);
    for(int val : arr){
        cout<<val<<" ";
    }
}