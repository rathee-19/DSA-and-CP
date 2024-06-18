#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
vector<int> majorityElement(vector<int> &nums)
{
    int cnt1 = 0;
    int cnt2 = 0;

    int ele1, ele2;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt1 == 0 && ele2 != nums[i])
        {
            ele1 = nums[i];
            cnt1++;
        }
        else if (cnt2 == 0 && ele1 != nums[i])
        {

            ele2 = nums[i];
            cnt2++;
        }
        else if (nums[i] == ele1)
        {
            cnt1++;
        }
        else if (nums[i] == ele2)
        {
            cnt2++;
        }
        else
        {
            cnt1--, cnt2--;
        }
    }
    int check1 = 0;
    int check2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == ele1)
        {
            check1++;
        }
        if (nums[i] == ele2)
        {
            check2++;
        }
    }
    int min = nums.size() / 3;
    if (check1 > min)
    {
        res.push_back(ele1);
    }
    if (check2 > min && ele1 != ele2)
    {
        res.push_back(ele2);
    }
    sort(res.begin(), res.end());

    return res;
}
vector<int> majorityElements(vector<int> &nums)
{
    vector<int> res;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    for (auto i : mp)
    {
        if (i.second > nums.size() / 3)
        {
            res.push_back(i.first);
        }
    }
    sort(res.begin(), res.end());
    return res;
}
int main()
{
    vector<int> arr = {0, 0, 0};
    vector<int> res = majorityElement(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
