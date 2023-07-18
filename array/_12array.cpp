#include <bits/stdc++.h>
using namespace std;
void mergeSortedArray(int a[], int b[], int m, int n)
{
    int arr[n + m];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else if (a[i] > b[j])
        {
            arr[k] = b[j];
            k++;
            j++;
        }
        else
        {
            arr[k] = a[i];
            k++;
            i++;
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < m)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n)
    {
        arr[k] = b[j];
        k++;
        j++;
    }

    k = 0;
    for (int x = 0; x < m; x++)
    {
        a[x] = arr[k];
        k++;
    }
    for (int x = 0; x < n; x++)
    {
        b[x] = arr[k];
        k++;
    }
}
void mergeusingGap(int a[], int b[], int m, int n)
{
    int gap = (m + n) / 2;
    while (gap > 0)
    {
        int i = 0;
        int j = i + gap;
        while (j < (m + n))
        {
            if (i < m && j < m)
            {
                if (a[i] > a[j])
                {
                    swap(a[i], a[j]);
                }
            }
            if (i < m && j >= m)
            {
                if (a[i] > b[j - m])
                {
                    swap(a[i], b[j - m]);
                }
            }
            if (i >= m && j >= m)
            {
                if (b[i - m] > b[j - m])
                {
                    swap(b[i - m], b[j - m]);
                }
            }
            i++;
            j++;
        }
        cout << gap << endl;
        for (int x = 0; x < m; x++)
        {
            cout << a[x] << " ";
        }

        for (int x = 0; x < n; x++)
        {
            cout << b[x] << " ";
        }
        cout << endl;
        gap = gap - 1;
    }
}
void insert(int a[], int m, int k)
{
    a[m - 1] = k;
    for (int i = m - 1; i >= 1; i--)
    {
        if (a[i] < a[i - 1])
        {
            swap(a[i], a[i - 1]);
        }
        else
            return;
    }
}
void mergeusingInsertion(int a[], int b[], int m, int n)
{
    int ls = m - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[ls] > b[i])
        {
            int tmp = b[i];
            b[i] = a[ls];
            insert(a, m, tmp);
        }
    }
}
int main()
{
    int a[] = {0, 2, 6, 8, 9, 10, 11, 12};
    int m = sizeof(a) / sizeof(a[0]);
    int b[] = {1, 3, 5, 7, 13};
    int n = sizeof(b) / sizeof(b[0]);
    // mergeSortedArray(a, b, m, n);
    // mergeusingGap(a, b, m, n);
    mergeusingInsertion(a, b, m, n);
    for (int x = 0; x < m; x++)
    {
        cout << a[x] << " ";
    }
    cout << endl;
    for (int x = 0; x < n; x++)
    {
        cout << b[x] << " ";
    }
}
