// Find min max in array
#include <bits/stdc++.h>
using namespace std;
// struct duo
// {
//     int min;
//     int max;
// };
// struct duo getMinMax(int a[], int n) // O(n)
// {
//     struct duo minmax;
//     int i;
//     if (n == 1)
//     {
//         minmax.min = a[0];
//         minmax.max = a[0];
//     }
//     if (a[0] > a[1])
//     {
//         minmax.min = a[1];
//         minmax.max = a[0];
//     }
//     else
//     {
//         minmax.min = a[0];
//         minmax.max = a[1];
//     }
//     for (int i = 2; i < n; i++)
//     {
//         if (minmax.min > a[i])
//         {
//             minmax.min = a[i];
//         }
//         if (minmax.max < a[i])
//         {
//             minmax.max = a[i];
//         }
//     }
//     return minmax;
// }
// struct duo getMinMaxusingTournament(int a[], int low, int high) // O(n) && O(logn)
// {
//     duo mml, mmr, mmt;
//     if (low == high)
//     {
//         mmt.min = a[low];
//         mmt.max = a[high];
//         return mmt;
//     }
//     if (low + 1 == high)
//     {
//         if (a[low]<a[high])
//         {
//             mmt.min = a[low];
//             mmt.max = a[high];
//         }
//         else
//         {
//             mmt.min = a[high];
//             mmt.max = a[low];
//         }
//         return mmt;
//     }
//     int mid = low + (high - low) / 2;
//     mml = getMinMaxusingTournament(a, low, mid);
//     mmr = getMinMaxusingTournament(a, mid + 1, high);
//     // compare minimums
//     if (mml.min < mmr.min)
//     {
//         mmt.min = mml.min;
//     }
//     else
//     {
//         mmt.min = mmr.min;
//     }
//     // compare maximums
//     if (mml.max > mmr.max)
//     {
//         mmt.max = mml.max;
//     }
//     else
//     {
//         mmt.max = mmr.max;
//     }
//     return mmt;
// }

// pair<int,int> sol(int arr[],int s,int e,pair<int,int>&p){
//     if(s==e){
//         p.first=arr[s];
//         p.second = arr[s];
//         return p;
//     }
//     if(s+1==e){
//         p.first=min(arr[s],arr[e]);
//         p.second =max(arr[s],arr[e]);

//         return p;
//     }
//     int m = (s+e)/2;
//     pair<int,int>l = sol(arr,s,m,p);
//     pair<int,int>r = sol(arr,m+1,e,p);

//     p.first = min(min(l.first,r.first),p.first);
//     p.second = max(max(l.second,r.second),p.second);

//     return p;
// }
// pair<int,int> getMinMaxusingTournament(int arr[],int n){
//     pair<int,int>p;
//     if(n==1){
//         p.first=arr[0];
//         p.second = arr[0];
//         return p;
//     }
    
//     p = sol(arr,0,n-1,p);
//     return p;
// }
pair<int,int> sol(int arr[],int s,int e){
    if(s==e){
        pair<int,int>p;
        p.first=arr[s];
        p.second = arr[s];
        return p;
    }
    if(s+1==e){
        pair<int,int>p;
        p.first=min(arr[s],arr[e]);
        p.second =max(arr[s],arr[e]);

        return p;
    }
    pair<int,int>p;
    int m = (s+e)/2;
    pair<int,int>l = sol(arr,s,m);
    pair<int,int>r = sol(arr,m+1,e);

    p.first = min(l.first,r.first);
    p.second = max(l.second,r.second);

    return p;
}
pair<int,int> getMinMaxusingTournament(int arr[],int n){
    pair<int,int>p;
    if(n==1){
        p.first=arr[0];
        p.second = arr[0];
        return p;
    }
    
    p = sol(arr,0,n-1);
    return p;
}
int main()
{
    int arr[] = {2,22,-3,6,9,0,18};
    int n = sizeof(arr) / sizeof(arr[0]);
    /*********************method 1***********************/ // O(n)
    // int max = INT_MIN;
    // int min = INT_MAX;
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     if (max < x)
    //     {
    //         max = x;
    //     }
    //     if (min > x)
    //     {
    //         min = x;
    //     }
    //     arr[i] = x;
    // }
    //  cout<<min<<"  "<<max;

    /*********************method 2***********************/
    //  duo p = getMinMax(arr,n);
    // cout<<p.max<<"  "<<p.min<<endl;

    /*********************method 3 tournament method***********************/
    pair<int,int> q = getMinMaxusingTournament(arr,n);
    cout << q.first << "  " << q.second << endl;
}