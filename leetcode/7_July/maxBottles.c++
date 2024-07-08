#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;
  
    int numWaterBottles(int numBottles, int numExchange) {
        if (numBottles < numExchange){
            return numBottles;
        }
        int ans = numBottles;
        int extra = 0;
        while(numBottles >= numExchange){
            extra = numBottles % numExchange;
            numBottles = numBottles / numExchange;
            ans += numBottles;
            numBottles += extra;
        }
        return ans;
        
    }

int main(){
    int ans = numWaterBottles(17, 3);
    cout<<ans;
    return 0;
}