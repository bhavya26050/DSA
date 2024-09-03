#include<iostream>
using namespace std;

int Partition(int arr[], int s, int e)
{
    int pivot = arr[s];

    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if(arr[i] <= pivot)
        {
            cnt++;
        }
    }
    
    // place pivot at right place
    int pivotindex = s + cnt;
    swap(arr[pivotindex], arr[s]);

    // left and right part 
    int i = s, j = e;
    while(i < pivotindex && j > pivotindex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotindex && j > pivotindex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    // Return the pivot index
    return pivotindex;
}

void QuickSort(int arr[], int s, int e)
{
    // base case
    if(s >= e) // should be s >= e, not s > e
        return;

    // Partition
    int p = Partition(arr, s, e);

    // left part sort
    QuickSort(arr, s, p - 1);

    // right part sort
    QuickSort(arr, p + 1, e);
}

int main()
{
    int arr[5] = {2, 4, 1, 6, 9};
    int n = 5;

    QuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
