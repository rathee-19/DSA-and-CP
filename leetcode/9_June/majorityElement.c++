#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
int majorityElement(vector<int> &nums)
{
    int count = 0;
    int ele = nums[0];
    for (int n = 0; n < nums.size(); n++)
    {

        if (ele == nums[n])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count > nums.size() / 2)
        {

            break;
        }
        if (count == 0)
        {
            ele = nums[n];
            count++;
        }
    }
    return ele;
}
// alternate approach using hashmap;
int MajorityElement(vector<int> &nums)
{
    unordered_map<int, int> mp;
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
    }
    return -1;
}

int main()
{
    vector<int> arr = {3, 1, 2, 2, 3,3};
    int n = arr.size();
    cout << majorityElement(arr) << endl;
    return 0;
}