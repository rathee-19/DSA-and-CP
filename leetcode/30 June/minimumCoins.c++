#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v = 49;
    vector<int> ans;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;
    //   for (int i = n - 1; i >= 0; i--) {
    //     while (V >= coins[i]) {
    //       V -= coins[i];
    //       ans.push_back(coins[i]);
    //     }
    //   }
    int sum = 0;
    int flag =0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v >= coins[i])
        {
            
            sum += v / coins[i];
            for (int j = 0; j <( v/coins[i]); j++)
            {
                ans.push_back(coins[i]);                /* code */
            }
            
            v = v % coins[i];

        }
        if(v == 0){
            flag =1;
            break;
        }
    }
    if(flag == 0){
        cout << "Not possible" << endl;
        return 0;
    }
    cout << "The minimum number of coins is " << sum << endl;
    // why is this not working? 

    // cout << "The minimum number of coins is " << ans.size() << endl;
    // cout << "The coins are " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}