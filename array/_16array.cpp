// For an array, inversion count indicates how far (or close) the array is from being sorted.
// If array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum.
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
#include <bits/stdc++.h>
using namespace std;
void merge(long long arr[], long long s, long long m, long long e, long long &cnt)
{
    int n1 = m - s + 1;
    int n2 = e - (m+1) + 1;
    long long a[n1];
    long long b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[s + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[m + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = s;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            j++;
            k++;
            cnt += (n1) - i;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}
void mergeSort(long long arr[], long long s, long long e, long long &cnt)
{
    if (s < e)
    {
        long long int m = s + (e - s) / 2;
        mergeSort(arr, s, m, cnt);
        mergeSort(arr, m + 1, e, cnt);
        merge(arr, s, m, e, cnt);
    }
    return;
}
long long int inversionCount(long long arr[], long long N)
{
    long long int cnt = 0;
    mergeSort(arr, 0, N - 1, cnt);
    return cnt;
}
int main()
{
    long long int arr[] = {2, 5, 5, 9, 0, 18, 6, 8, 9, -1, 9, 16};
    long long int n = sizeof(arr) / sizeof(arr[0]);
    cout<<inversionCount(arr,n);
}