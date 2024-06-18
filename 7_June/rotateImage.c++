#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
void rotate(vector<vector<int>> &matrix)
{
    int n;
    // n = matrix[0].size()-1;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i + 1; j < matrix[i].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]); /* code */
        }
    }
    //      for (int i = 0; i < matrix.size(); i++) {
    //     reverse(matrix[i].begin(), matrix[i].end());    //  by reversing the row
    // }
    for (int i = 0; i < matrix.size(); i++)                  // same by swapping the elements fo colomns
    {
        n = matrix.size()-1;
        for (int j = 0; j < matrix[i].size() / 2; j++)
        {
            swap(matrix[i][j], matrix[i][n]);
            n--;
        }

    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
            /* code */
        }
        cout << endl;
        /* code */
    }

    return 0;
}