#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (matrix.empty() || matrix[0].empty())
    {
        return false;
    }

    int n = matrix.size();
    int m = matrix[0].size() - 1;
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][m] < target)
        {
            continue;
        }
        else
        {
           return binary_search(matrix[i].begin(), matrix[i].end(), target);


            // while (target < matrix[i][m] && m >= 0)
            // {
            //     m--;
            // }
            // cout << "came here";
            // if ( target == matrix[i][m])
            // {
            //     return true;
            // }
            // else
            // {
            //     return false;
            // }


            /* code */
        }
    }
    return false;
}
//flatten into a 1d method remembered from cso 
bool SearchMatrix1(vector<vector<int>> &matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    int start = 0;
    int end = n*m - 1;
    while (start <= end)
    {
        int mid = start + (end - start)/2;
        if (matrix[mid/m][mid%m] == target)
        {
            return true;
        }
        else if (matrix[mid/m][mid%m] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        
    }
    return false;
}

int main()
{
    vector<vector<int>> arr = {{0}};
    bool ans = searchMatrix(arr, 0);
    cout << ans << endl;
    return 0;
}