#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &nums)
{
    int flag = 0;

    for (int i = nums.size() - 1; i > 0; i--)
    {
        if (nums[i] > nums[i - 1])
        {
            int test = nums[i - 1];
            for (int j = nums.size() - 1; j > i - 1; j--)
            {
                if (nums[j] > test)
                {
                    swap(nums[j], nums[i - 1]);
                    break;
                }
            }
            sort(nums.begin() + i, nums.end());
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        reverse(nums.begin(), nums.end());

        // sort(nums.begin(), nums.end());
    }
}
//     if (flag ==2 ){
//         int test = nums[0];
//         for (int i = nums.size()-1; i > 0; i--)
//         {
//             if (nums[i]>test){
//                 swap(nums[i], nums[0]);
//                 break;
//             }
//         }
//         sort(nums.begin()+1, nums.end());

//     }

// }

int main()
{
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}