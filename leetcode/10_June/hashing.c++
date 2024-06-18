#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
int hashingLearn(vector<int> &nums, int target)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {

        mp[nums[i]]++;
    }

    for (auto i : mp)
    {
        if (i.second > nums.size() / 2)
        {
            return i.first;
        }
        // cout << i.first << " " << i.second << endl;
    }

    return 0;
    // return mp[target];
}
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target - nums[i]) != mp.end())
        {
            res.push_back(mp[target - nums[i]]);
            res.push_back(i);
            break;
        }
        mp[nums[i]] = i;
      
        /* code */
    }
    return res;
}
int main()
{

    string input = "rohan";
    vector<int> arr = {3,2,4};
    int target = 6;
    // int ans = hashingLearn(arr, 0);
    vector <int> res = twoSum(arr,target);
    for (int i = 0; i < res.size(); i++)
    {
        cout<< res[i] << " ";
        /* code */
    }
    
    // twoSum(arr,target);

    // cout << ans << endl;

    return 0;
}