#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
int merge(vector<int> &A, int start, int mid, int end)
{
    int cnt = 0;
    int p = start, q = mid + 1;
    vector<int> Arr;
    for (int i = start; i <= end; i++)
    {
        if (p > mid)
        {
            Arr.push_back(A[q++]);
        }
        else if (q > end)
        {
            Arr.push_back(A[p++]);
        }
        else if (A[p] < A[q])
        {
            Arr.push_back(A[p++]);
        }
        else
        {
            Arr.push_back(A[q++]);
            cnt += (mid - p + 1);
        }
    }
    for (int i = 0; i < Arr.size(); i++)
    {
        A[start++] = Arr[i];
    }
    return cnt;
}

int mergeSort(vector<int> &A, int start, int end)
{
    int cnt = 0;
    if (start < end)
    {
        int mid = (start + end) / 2;
        cnt += mergeSort(A, start, mid);
        cnt += mergeSort(A, mid + 1, end);
        cnt += merge(A, start, mid, end);
    }
    return cnt;
}

int main()
{
    vector<int> arr = {3, 1, 2, 5, 3};
    int n = arr.size();
    int cnt = mergeSort(arr, 0, n - 1);
    cout << cnt << endl;

    return 0;
}