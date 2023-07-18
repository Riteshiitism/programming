// reverse the array
#include <bits/stdc++.h>
using namespace std;
void reverse_array(int a[], int n)                                       //O(n)  && O(n)
{
    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[n - i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
}
void reverse_arrayrecursively(int a[], int n)                            //O(n)
{
    if (n == 0)
    {
        return;
    }  
    cout << a[n-1] << " ";   
    reverse_arrayrecursively(a, n - 1);
    
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void reverse_Samearray(int a[], int n)                                   //O(n)
{
    int first = 0;
    int last = n - 1;
    while (first <= last)
    {
        swap(&a[first], &a[last]);
        // int tmp = a[first];
        // a[first]=a[last];
        // a[last]=tmp;
        first++;
        last--;
    }
    // a[3]=0;
}
void reverse_Samearrayrecursively(int a[], int first, int last)          //O(n)
{
    if (first > last)
    {
        return;
    }
    swap(&a[first], &a[last]);
    first++;
    last--;
    reverse_Samearrayrecursively(a, first, last);
}
int main()
{
    // int n;
    // cin >> n;
    int arr[] ={2,5,6,98,0,23,-56};
    int n = sizeof(arr)/sizeof(arr[0]);
    //  reverse_array(arr,n);
    // reverse_arrayrecursively(arr,n);
    //  reverse_Samearray(arr,n);
    int first = 0;
    int last = n - 1;
     reverse_Samearrayrecursively(arr, first, last);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}