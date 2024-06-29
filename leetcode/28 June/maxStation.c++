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
int findPlatform(int start[], int end[], int n)
{
    rail arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].end = end[i];
        arr[i].start = start[i];
    }
    // sort arr[] according to end time
    sort(arr, arr + n, [](rail &a, rail &b)
         { return a.end < b.end; });
    int limit = arr[0].end;
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].start < limit)
        {
            count++;
            limit = arr[i].end;
        }
        

    }
    return count;
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