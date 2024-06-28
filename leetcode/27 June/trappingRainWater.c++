#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    int fill = 0;
    if (n < 3)
    {
        return fill;
    }
    int i = 0;
    int j = 1;

    int temp = 0;
    int count = 1;
    int temp2 = 0;
    int pre;
    while (j < n)
    {
        pre = height[j];
        if (height[j] >= height[i])
        {
            fill += temp;
            i = j;
            j++;
        }
        if (height[i] > height[j])
        {
            temp += height[i] - height[j];
            // pre = height[j];
            j++;
        }
        if (height[j] == pre)
        {
            count++;
        }
        if (height[j] > pre)
        {
            fill += count * (height[j] - pre);
            count++;
        }
    }
    return fill;
}
// solution 2 correct one
int trap1(vector<int> &height)
{
    int ans = 0;

    int n = height.size();
    if (n < 3)
    {
        return ans;
    }
    int left = 0;
    int right = n - 1;
    int max1 = 0;
    int max2 = 0;

    while (right >= left)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= max1)
            {
                max1 = height[left];
            }
            else
            {
                ans += max1 - height[left];
            }
            left++;
        }
        else
        {
            if (height[right] >= max2)
            {
                max2 = height[right];
            }
            else
            {
                ans += max2 - height[right];
            }
            right--;
        }
    }
    return ans;
}
int main()
{
    vector<int> height = {4, 2, 0, 3, 2, 5};
    int ans = trap1(height);
    cout << ans << endl;
    return 0;
}