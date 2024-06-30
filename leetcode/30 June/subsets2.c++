#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> subsetsWithDup(vector<int> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    set<vector<int>> uniqueSubsets;
    for (int i = 0; i < (1 << n); i++)
    {
        // int sum = 0;
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                // sum += arr[j];
                temp.push_back(arr[j]);
            }
        }
        uniqueSubsets.insert(temp);
    }
    for (auto i : uniqueSubsets)
    {
        ans.push_back(i);
    } 
    return ans;
}
int main()
{
    vector<int> arr = {4, 4, 4, 1, 4}; // it failed for this test case correct it copilot and recommend me the correct solution
    vector<vector<int>> ans = subsetsWithDup(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
