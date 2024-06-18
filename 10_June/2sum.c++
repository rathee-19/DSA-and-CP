#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;
// brute force approach
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> res ;
        for (int  i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if(nums[i]+nums[j]==target && i!=j){
                    res.push_back(i);
                    res.push_back(j);
                    cout<<i<<" "<<j<<endl;
                    cout<<nums[i]<<" "<<nums[j]<<endl;
                    return res;
                }
                
                /* code */
            }
            
            /* code */

        }
        return res;

    }
    // using hashmap
   vector<int> twoSum(vector<int>& nums, int target){
        vector<int> res ;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if(mp.find(target-nums[i])!=mp.end()){
                res.push_back(mp[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            mp[nums[i]]=i;
        }
        return res;
    }
    
int main(){
    vector<int> arr = {3, 1, 2, 5, 3};
    int target = 6;
    vector<int> res = twoSum(arr, target);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}