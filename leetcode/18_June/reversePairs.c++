#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;
int merge(vector<int> &A, int start, int mid, int end)
{
    int cnt = 0;
    int p = start, q = mid + 1;
    int flag =0;
    for (int i = p; i < q; i++)
    {
        for (int j = q; j<=end; j++)
        {
            
            if (A[i] > 2*A[j])
            {
                flag =1;
                continue;
            }
            else if (flag ==1){
                cout << p << " " << q << " " << i << " " << j << endl;
                cnt = cnt + (j-q);
                flag = 0;
                break;
            }
            else{
                break;
            }
        }
        
    }
    // //       // Counting reverse pairs
    // for (int i = start; i <= mid; ++i) {
    //     while (q <= end && static_cast<long long>(A[i]) > 2LL * A[q]) {
    //         q++;
    //     }
    //     cnt += (q - (mid + 1));
    // }

    // Reset pointers for merging
    p = start;
    q = mid + 1;

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
            // cnt += (mid - p + 1);
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


int main() {
    vector<int> arr = { 5, 2, 8, 3, 1, 6, 9, 4, 7 };
    int n = arr.size();

    int ans = mergeSort(arr, 0, n - 1);
    cout << ans    << endl;
    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}

