#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;
      vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int> temp;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n-2; i++)
        {
                sum += nums[i];
            for (int j = i+1; j < n-1; j++)
            {
                sum+= nums[j];
                for (int k = j+1; k< n; k++)
                {
                    if (nums[k] == (-sum)){
                        temp = {nums[i],nums[j],nums[k]};
                        ans.push_back(temp);
                    }

                }
                

            }
            
        }
        return ans;
        
        
    }
int main(){
    vector<int> input = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSum(input);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " "<< ans[i][j] << " ";
        }
        cout << endl;
        
        /* code */
    }
    
    return 0;
}