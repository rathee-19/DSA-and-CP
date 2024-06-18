#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// vector<vector<int>> genrate(int numRows)
// {
//     vector<vector<int>> res;
//     for (int i = 0; i < numRows; i++)
//     {
//         vector<int> row(i + 1, 1);
//         for (int j = 1; j < i; j++)
//         {
//             row[j] = res[i - 1][j - 1] + res[i - 1][j];
//         }
//         res.push_back(row);
//     }
// }
vector<int> getRow(int row)
{
    int ans = 1;
    vector<int> res(row + 1, 1);
    for (int i = 1; i < row; i++)
    {
        ans = ans * ((row + 1) - i);
        ans = ans / i;
        // cout<< ans << "iteration number : " << i;;
        res[i]=ans;
    }
    return res;
}
int main()
{
    // int numRows;
    // cin >> numRows;
    // vector<vector<int>> res = genrate(numRows);
    // for (int i = 0; i < res.size(); i++)
    // {
    //     for (int j = 0; j < res[i].size(); j++)
    //     {
    //         cout << res[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<int> res = getRow(5);
    for (int i = 0; i < 5; i++)
    {
        cout << res[i];
    }
}