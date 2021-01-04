#include <iostream>
using namespace std;
void merge(int *a, int si, int ei, int mid)
{

    //     if (a[i] < a[j])
    //     {
    //         output[k] = a[j];

    //         k++;
    //         i++;
    //     }
    //     else
    //     {

    //         output[k] = a[i];

    //         k++;
    //         j++;
    //     }
    // }
    // for (; i <= mid; i++)
    // {
    //     output[k] = a[i];
    //     k++;
    // }
    // for (; j <= ei; j++)
    // {
    //     output[k] = a[j];
    //     k++;
    // }
    // for (i = si; i < k; i++)
    // {
    //     cout << output[i] << " ";
    // }
    int i, j, k, c[50];
    i = si;
    k = si;
    j = mid + 1;
    while (i <= mid && j <= ei)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= ei)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = si; i < k; i++)
    {
        a[i] = c[i];
    }
}

void merge_sort(int *a, int si, int ei)
{
    int mid;
    if (si < ei)
    {
        mid = (si + ei) / 2;
        merge_sort(a, si, mid);
        merge_sort(a, mid + 1, ei);

        merge(a, si, ei, mid);
    }
}

int main()
{
    int a[] = {3, 11, 7, 5, 3, 2, 53, 21, 4, 0};
    merge_sort(a, 0, 9);
    cout << "Sorted array\n";
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
}
