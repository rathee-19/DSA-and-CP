#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
void combinations(int i, vector<int> &arr, int target, vector<int> &temp, vector<vector<int>> &ans)
{
 if (target == 0) {
    ans.push_back(temp);
    return;
  }
  for (int j = i; j < arr.size(); j++) {
    if (j > i && arr[j] == arr[j - 1]) continue;
    if (arr[j] > target) break;
    temp.push_back(arr[j]);
    combinations(j + 1,arr,target-arr[j],temp,ans);
    temp.pop_back();
  }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    combinations(0, candidates, target, temp, ans);
    return ans;
}
void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
  if (target == 0) {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < arr.size(); i++) {
    if (i > ind && arr[i] == arr[i - 1]) continue;
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    findCombination(i + 1, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}
vector < vector < int >> combinationSum2(vector < int > & candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector < vector < int >> ans;
  vector < int > ds;
  findCombination(0, target, candidates, ans, ds);
  return ans;
}
int main()
{
    vector<int> arr = {2, 3, 12, 7};
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
    return 0;
}