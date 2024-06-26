#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
int removeDuplicates(vector<int> &nums)

{

    int i = 0;
    int j = 1;
    if(nums.size()==0){
        return i;
    }
    if ( nums.size()==1){
        return j;
    }

    while (j < nums.size())
    {

        // j = i + 1;

        while (j < nums.size() && nums[j] == nums[i]  ) 
        {
            // count = count + 1;

            j++;
        }
        if (j == nums.size())
        {
        return i+1;
        }
        nums[i + 1] = nums[j];
        i++;
        j++;
    }

    return i + 1;
}

// optimized solution 
class Solution {
public:
 int removeDuplicates(vector<int> &nums)

{

    int i = 0;
    int j = 1;
    if(nums.size()==0){
        return i;
    }
    if ( nums.size()==1){
        return j;
    }

   while (j < nums.size()) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
        j++;
    }
    return i + 1;
}
};
int main()
{
    vector<int> input = {0, 0};
    int ans = removeDuplicates(input);
    cout << ans << endl;

    return 0;
}