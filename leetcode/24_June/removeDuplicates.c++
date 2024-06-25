#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int k=n;

    int j=0;
    for (int i = 0; i < n; i++)
    {
        j =i+1;
        if (j==n){
            break;
        }
        while(nums[j]==nums[i]){
            j++;
            k--;
        }
        i =j;
        cout << i << j << k <<endl;

    }
    
    return k;
}
int main()
{
    vector<int> input = {0,0,1,1,1,2,2,3,3,4};
    int ans = removeDuplicates(input);
    
    return 0;
}