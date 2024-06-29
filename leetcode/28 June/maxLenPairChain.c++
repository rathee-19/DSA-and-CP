#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;
     int findLongestChain(vector<vector<int>>& pairs) {
        int ans;
        sort (pairs.begin(), pairs.end(),[] (vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        int limit = pairs[0][1];
        int count =1;
        for (int i = 0; i < pairs.size(); i++)
        {
            if (pairs[i][0] > limit)
            {
                count++;
                limit = pairs[i][1];
            }
        }
        return count;

        

    }
int main(){
    vector<vector<int>> pairs = {{1,2},{2,3},{3,4}};
    int ans = findLongestChain(pairs);
    cout << ans << endl;
    
    return 0;
}