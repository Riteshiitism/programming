#include<bits/stdc++.h>
using namespace std;
int profit(int prices[],int n){
    int sell = prices[n-1];
    int maxProfit = 0;
    for (int i = n-2; i >= 0; i--)
    {
        if(prices[i]>=sell){
            sell = prices[i];
        }
        else{
            int profit = sell-prices[i];
            maxProfit=max(maxProfit,profit);
        }
    }
    return maxProfit;
    
}
int main(){
    int arr[] = {7,1,5,3,6,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<profit(arr,n);
}