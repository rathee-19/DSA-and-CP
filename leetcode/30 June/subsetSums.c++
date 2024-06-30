#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;
      vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> ans;
        for(int i = 0; i < (1 << n); i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    sum += arr[j];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
    // recursive approach
    void subsetSumsUtil(vector<int> arr, int n, int index, int sum,  vector<int> &ans){
        if(index == n){
            ans.push_back(sum);
            return;
        }
        subsetSumsUtil(arr, n, index + 1, sum + arr[index] , ans);
        subsetSumsUtil(arr, n, index + 1, sum,  ans);
    }
    vector<int> subsetSums1(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> ans;
        subsetSumsUtil(arr, n, 0, 0,  ans);
        return ans;
    }
int main(){
    vector<int> arr = {1, 2, 3};
    vector<int> ans = subsetSums1(arr, 3);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}