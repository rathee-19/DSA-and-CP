#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;
  // normal better approach
    void sortColors(vector<int>& nums) {
      int red =0;
      int  white =0; 
      int blue = 0;


    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0){
            red++;
        }
        if (nums[i] == 1){
            white++;
        }
        if (nums[i] == 2){
            blue++;
        }
        
    }
    nums.clear();
      for (int i = 0; i < red; i++)
      {
        nums.push_back(0);
        
      }
        for (int i = 0; i < white; i++)
      {
        nums.push_back(1);
        
      }
        for (int i = 0; i < blue; i++)
      {
        nums.push_back(2);
        
      }
      
    
    }

// optimal approach 

void sortColor(vector<int> &nums){
    int low = 0;
    int mid = 0;
    int high = nums.size()-1;

    while(mid<=high){
        if (nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
int main(){
    vector<int> nums = {2,0,2,1,1,0};
    sortColor(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}