#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}
// other approach using recursion
int uniquePaths1(int m, int n)
{
    int count = 0;
    if (m == 1 || n == 1)
    {
        return 1;
    }
    count += uniquePaths1(m - 1, n);
    count += uniquePaths1(m, n - 1);
    return count;
}
// other apporach using recursion but starting from 0,0
int uniquePaths2(int m, int n)
{

    int i = 0;
    int j = 0;
    vector<vector<int>> dp(m, vector<int>(n, 1));
    if (i == m - 1 || j == n - 1)
    {
        cout << i << " " << j << endl;
        return 1;
    }
    if (dp[i][j] != 1)
    {
        return dp[i][j];
    }
    else
    {
        return dp[i][j] = uniquePaths2(m - 1, n) + uniquePaths2(m, n - 1);
    }
}
// other approach using mathematical formula
int uniquePaths3(int m, int n)
{
    int N = m + n - 2;
    int r = m - 1;
    double res = 1;
    for (int i = 1; i <= r; i++)
    {
        res = res * (N - r + i) / i;
    }
    return (int)res;
}
int main()
{
    // cout<<uniquePaths(3, 7)<<endl;
    int ans = uniquePaths2(3, 4);
    cout << ans << endl;
    return 0;
}