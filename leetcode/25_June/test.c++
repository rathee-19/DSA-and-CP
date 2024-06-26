#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    set<vector<int>> s;
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n - 2; i++)
    {
        map<int, int> h;
        for (int j = i + 1; j < n; j++)
        {
            int sum = nums[i] + nums[j];
            if (h.find(-sum) != h.end())
            {
                temp = {nums[i], nums[j], -sum};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
            else
            {
                h[nums[j]] = j;
            }
        }
    }
    for (auto i : s)
    {
        ans.push_back(i);
    }
    return ans;
}
int main()
{
    return 0;
}