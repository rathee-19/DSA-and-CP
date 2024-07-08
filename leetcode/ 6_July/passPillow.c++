#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;
     int passThePillow(int n, int time) {
      int ans;
      if (time<n){
        ans = time+1;
      }
      else{
        int d = 1;
        int pos =1;
        while(time){
            if (pos==n){
                d = -1;
            }
            if (pos==1){
                d = 1;
            }
            pos+=d;
            time--;

            
        }
        ans = pos;
      }

      return ans;
    }
    // solution 2 
         int passThePillow(int n, int time) {
      int ans;
      if (time<n){
        ans = time+1;
        return ans;
      }
      int t = time % (n-1);
      if(t%2){
       ans =  n-time%(n-1);
      }
      else{
       ans = time%(n-1)+1;
      
      }

      return ans;
    }
int main(){
    int n =3;
    int time = 2;
    cout<<passThePillow(n, time);

    return 0;

}