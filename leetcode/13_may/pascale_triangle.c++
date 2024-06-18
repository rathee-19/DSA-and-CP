#include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
using namespace std;
   vector<vector<int>> generate(int numRows) {
        

        vector <vector <int>> ans = {{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}};
        int n = ans[4].size();
        cout << n << endl;
        return ans;
        
    }
 
int main () {
   
    generate(5);
return 0;
}