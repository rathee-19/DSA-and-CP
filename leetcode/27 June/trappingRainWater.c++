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
int trap(vector<int> &height)
{
    int ans = 0;
    int left;
    int right;
    int n = height.size();
    if (n < 3)
    {
        return ans;
    }
    left = 0;
    right = n - 1;
    int max1 = height[0];
    int max2 = height[right];
    int current;
    
    
    while (right > left)
    {   
        max1 = max (max1, height [left]);
        max2 = max(max2, height[right]);
        current = min (max1, max2);

        
        if (height [left]>=max1 ){
            left++;
        }
        if heigt
    }
}
int main()
{
    vector<int> height = {4, 2, 0, 3, 2, 5};
    int ans = trap(height);
    cout << ans << endl;
    return 0;
}