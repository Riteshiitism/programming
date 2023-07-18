#include <bits/stdc++.h>
using namespace std;
int findLongestConseqSubseq(int arr[], int n)
{
    unordered_map<int, bool> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]] = 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int c = 1;
        if (m[arr[i] - 1])
            continue;
        else
        {
            while (m[arr[i] + c])
            {
                c++;
            }
            res = max(res, c);
        }
    }
    return res;
}
int main(){
    int arr[] = {2,6,1,9,4,5,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<findLongestConseqSubseq(arr,n);
}