#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int n1 = nums1.size();
    int n2 = nums2.size();

    if (n1 > n2)
    {
        return intersect(nums2, nums1);
    }

    vector<int> ans;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (nums1[i] == nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}
vector<int> intersect1(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n1 > n2)
    {
        return intersect(nums2, nums1);
    }
    int arr[n2] = {0};
    vector <int> ans;
    for (int i = 0; i < n2; i++)
    {
        arr[nums2[i] ] ++;
                /* code */
    }
    for (int i = 0; i < n1; i++)
    {
        if(arr[nums1[i]] > 0 ){
            while(arr[nums1[i]]){
                ans.push_back(nums1[i]);

            }
        }
    }
    return ans;
    
}
int main()
{
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> ans = intersect1(nums1, nums2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}