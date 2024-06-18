#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int> &nums) {
    int count = 0;
    int res = nums[0]; // Initialize to the first element to handle all negative numbers case
    vector<int> resArr;
    vector<int> tempArr;

    for (int i = 0; i < nums.size(); i++) {
        count += nums[i];
        tempArr.push_back(nums[i]);
        
        if (count > res) {
            res = count;
            resArr = tempArr;
        }
        
        if (count < 0) {
            count = 0;
            tempArr.clear();
        }
    }

    cout << "The subarray is: ";
    for (int i = 0; i < resArr.size(); i++) {
        cout << resArr[i] << " ";
    }
    cout << endl;

    return res;
}

int main() {
    vector<int> nums = {-1, -2, 3, 4, 5, -1};
    cout << "Maximum subarray sum: " << maxSubArray(nums) << endl;
    return 0;
}
