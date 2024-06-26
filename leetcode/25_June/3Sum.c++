#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
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
                vector<int> temp = {nums[i], nums[j], -sum};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
            else
            {
                h[nums[j]] = j;
            }
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());

    return ans;
}
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            // Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            // Find the element in the set:
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    // store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
//   vector<vector<int>> threeSum(vector<int> &nums)
// {
//     set<vector<int>> s;
//         vector<int> temp;

//     int n = nums.size();
//     int sum = 0;
//     for (int i = 0; i < n - 2; i++)
//     {
//         map<int, int> h;
//         for (int j = i + 1; j < n; j++)
//         {
//             int sum = nums[i] + nums[j];
//             if (h.find(-sum) != h.end())
//             {
//                 temp = {nums[i], nums[j], -sum};
//                 sort(temp.begin(), temp.end());
//                 s.insert(temp);
//             }
//             else{
//             h[j] = nums[j];
//             }
//         }
//     }
//         vector<vector<int>> ans;

//       for (auto i : s)
//     {
//         ans.push_back(i);
//     }
//     return ans;
// }

// most optimal approach ;
vector<vector<int>> threesum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum > 0)
            {
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {

                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> input = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    vector<vector<int>> ans = threesum(input);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << ans[i][j] << " ";
        }
        cout << endl;

        /* code */
    }

    return 0;
}