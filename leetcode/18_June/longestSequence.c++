#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <unordered_set>

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
int longestConsecutive(vector<int> &a){
    int n = a.size();
    if ( n == 0)
    {
        return 0;
    }   
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
        /* code */
    }
    int ans =1;
    for (int i = 0; i < n; i++)
    {
        if (s.find(a[i]-1) == s.end())
        {
            int j = a[i];
            while (s.find(j) != s.end())
            {
                j++;
            }
            ans = max(ans, j-a[i]);
        }
        /* code */
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