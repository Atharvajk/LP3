#include <bits/stdc++.h>
using namespace std;

int partition(int start, int end, vector<int> &arr)
{
    int pivot = arr[start];
    int i = start + 1;

    for (int j = start + 1; j <= end; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[start], arr[i - 1]);
    return i - 1;
}

int randomPivot(int start, int end)
{
    return start + rand() % (end - start + 1);
}

int randomPartition(int start, int end, vector<int> &arr)
{
    int pivotindex = randomPivot(start, end);
    swap(arr[start], arr[pivotindex]);

    int pivot = arr[start];
    int i = start + 1;

    for (int j = start + 1; j <= end; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[start], arr[i - 1]);
    return i - 1;
}

void quicksort(int start, int end, vector<int> &arr, bool rand)
{
    if (start >= end)
    {
        return;
    }

    int p;
    if (rand)
    {
        p = randomPartition(start, end, arr);
    }
    else
    {
        p = partition(start, end, arr);
    }

    quicksort(start, p - 1, arr, rand);
    quicksort(p + 1, end, arr, rand);
}
int main()
{
    cout << "Enter the size of array : " << endl;
    int n;
    cin >> n;

    vector<int> arr(n), arrcopy(n);

    cout << "Enter the elements of array : " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    arrcopy = arr;

    cout << "Randomised quicksort : " << endl;
    quicksort(0, n - 1, arr, true);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Deterministic quicksort : " << endl;
    quicksort(0, n - 1, arrcopy, false);
    for (int i = 0; i < n; i++)
    {
        cout << arrcopy[i] << " ";
    }
    return 0;
}