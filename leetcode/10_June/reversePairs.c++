#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
 int merge(vector<int> &A, int start, int mid, int end) {
        int cnt = 0;
        int p = start, q = mid + 1;
        vector<int> Arr;

        // Counting reverse pairs
        for (int i = start; i <= mid; ++i) {
            while (q <= end && static_cast<long long>(A[i]) > 2LL * A[q]) {
                q++;
            }
            cnt += (q - (mid + 1));
        }

        // Reset pointers for merging
        p = start;
        q = mid + 1;

        // Merge process
        for (int i = start; i <= end; i++) {
            if (p > mid) {
                Arr.push_back(A[q++]);
            } else if (q > end) {
                Arr.push_back(A[p++]);
            } else if (A[p] <= A[q]) {
                Arr.push_back(A[p++]);
            } else {
                Arr.push_back(A[q++]);
            }
        }

        for (int i = 0; i < Arr.size(); i++) {
            A[start + i] = Arr[i];
        }

        return cnt;
    }

    int mergeSort(vector<int> &A, int start, int end) {
        int cnt = 0;
        if (start < end) {
            int mid = (start + end) / 2;
            cnt += mergeSort(A, start, mid);
            cnt += mergeSort(A, mid + 1, end);
            cnt += merge(A, start, mid, end);
        }
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

int main()
{
    vector<int> arr = {2,4,3,5,1};
    int n = arr.size();
    int cnt = reversePairs(arr);

    cout << cnt << endl;

    return 0;
}