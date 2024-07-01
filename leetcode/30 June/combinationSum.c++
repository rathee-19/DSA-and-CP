#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
// other approach then recursion
void combinations(int i, vector<int> &arr,vector<vector<int>> &ans, vector<int>& temp, int target){
    if(i == arr.size()){
        if(target == 0){
            ans.push_back(temp);
        }
        return;
    }
    if(arr[i]<=target){
        temp.push_back(arr[i]);
        combinations(i,arr,ans,temp,target-arr[i]);
        temp.pop_back();

    }
    combinations(i+1,arr,ans,temp,target);

}


vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans ;
    vector <int > temp;
     combinations(0,candidates,ans,temp,target);
    return ans;

}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    vector<vector<int>> ans = combinationSum(arr, 7);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}