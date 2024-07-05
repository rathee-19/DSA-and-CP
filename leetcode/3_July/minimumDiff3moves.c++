#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
int minDifference(vector<int> &nums)
{
    int n = nums.size();
    if (n < 5)
    {
        return 0;
    }
    sort(nums.begin(), nums.end());
    int dif = 10000000000;

    for (int i = 0; i <= 3; i++)
    {
        dif = min(dif, nums[n - (3 - i) - 1] - nums[i]);
    }

    return dif;
}
int minDifference1(vector<int> &nums)
{
    int n = nums.size();
    if (n < 5)
    {
        return 0;
    }
    sort(nums.begin(), nums.end());
    int backDif = nums[n - 4] - nums[0];
    int frontDif = nums[n - 1] - nums[3];
    int backDif2 = nums[n - 3] - nums[1];
    int frontDif2 = nums[n - 2] - nums[2];
    backDif = min(backDif2, backDif);
    frontDif = min(frontDif, frontDif2);
    return min(backDif, frontDif);
}
int main()
{
    vector<int> num = {1, 5, 0, 10, 14};
    int ans = minDifference(num);
    cout << ans << endl;
    return 0;
}