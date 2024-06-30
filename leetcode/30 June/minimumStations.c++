#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
struct rail
{
    int start;
    int end;
};
int findPlatform1(int start[], int end[], int n)
{
    rail arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].end = end[i];
        arr[i].start = start[i];
    }
    // sort arr[] according to end time
    sort(arr, arr + n, [](rail &a, rail &b)
         { return a.start < b.start; });
   
    
    int limit = arr[0].end;
    int count = 1; 
    int ans= 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].start < limit)
        {
            count++;
            limit = max(limit, arr[i].end);
        }
        else{
            limit = arr[i].end;
            count =1;
        }
            ans = max (count,ans);
        

    }
    return ans;
}
// correct solution 
int findPlatform( int start[], int end[], int n){
    sort(start, start+n);
    sort(end, end+n);
    int i =1;
    int j =0;
    int count =1;
    int maxP = 1;
    while (i<n && j< n){
        if (start[i]<=end[j]){
            count ++;
            i++;

        }
        else{
            count --;
            j++;
        }
        maxP = max(maxP,count);
    }
    return maxP;
}
int main()
{
//    int arr[] = {0900, 940, 950, 1100, 1500, 1800}, dep[] = {910, 1200, 1120, 1130, 1900, 2000};
// give two array input for arrival and departure times of train as given in above comment

    int arr[] = {900, 940, 950, 1100, 1500, 1800}, dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    // give this input arr 0900 1100 1235 dep = 1000 1200 1240
    // int arr[] = {900, 1100, 1235}, dep[] = {1000, 1200, 1240};
   int n = 6;
   int ans = findPlatform(arr,dep,n);
   cout << ans << endl;

    return 0;
}