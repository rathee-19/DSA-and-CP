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
    int count =0;
    
    
    while (j < n)
    {
        if (height[j] >= height[i])
        {
            fill += temp;
            i = j;
            j++;
        }
        int pre = height[j];
        if (height[i] > height[j])
        {
            temp += height[i] - height[j];
            pre = height[j];
            j++;
        }
        if (height[j]>pre){



        }
    }
    return fill;
}
int main()
{
    vector<int> height = {4,2,0,3,2,5};
    int ans = trap (height);
    cout << ans << endl;
    return 0;
}