#include <bits/stdc++.h>
using namespace std;

// relative order remains same
// split in pos and negative then rearrange  
// O(n) and O(n)
void rearrange1(int arr[], int N)       
{
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] >= 0)
        {
            pos.push_back(arr[i]);
        }
        else
        {
            neg.push_back(arr[i]);
        }
    }
    int p = 0;
    int n = 0;
    int i = 0;
    while (p < pos.size() && n < neg.size())
    {
        if (i % 2 == 0)
        {
            arr[i] = pos[p];
            i++;
            p++;
        }
        else
        {
            arr[i] = neg[n];
            i++;
            n++;
        }
    }
    while (p < pos.size())
    {
        arr[i] = pos[p];
        i++;
        p++;
    }
    while (n < neg.size())
    {
        arr[i] = neg[n];
        i++;
        n++;
    }

    return;
}

// relative order does not remain same
// shift all negative value at end and then rearrange  
// O(n) and O(1)  extra 

void rearrange2(int arr[], int N){
    int s = -1;
    int e = N;
    while(1){
        do{
            s++;
        }while(arr[s]>=0);
        do{
            e--;
        }while(arr[e]<0);

        if(s>=e)  break;;


        swap(arr[s],arr[e]);
        
    }
    int ptr = 0;
    for (int i = 0; i < N; i++)
    {
        if(arr[i]<0){
            ptr = i;
            break;
        }
    }
    int i = 1;
    while(i < ptr && ptr<N){
        if(arr[i]>=0){
            swap(arr[i],arr[ptr]);
            i=i+2;
            ptr++;
        }
    }
    return;
}   
int main()
{
    int arr[] = {0, -1, 2, -3, 4,-1};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange2(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}