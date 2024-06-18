#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;
int longestConsecutive(vector<int> &nums)
{
    map<int,int> mp;
    int count = 0;
    int ans;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
        cout << mp[nums[i]] << endl;
        /* code */
    }
    for (auto i : mp)
    {
        if (i.second > 0)
        {
            count++;
            ans = max(ans, count);
        }

        else
        {
            count = 0;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 7, 8, 9};
    int ans = longestConsecutive(nums);
    cout << ans << endl;
    return 0;
}