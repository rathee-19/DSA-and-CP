#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
struct meet
{
    int start;
    int end;
    int pos;
};
int maxMeetings(int start[], int end[], int n)
{
    meet arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].end = end[i];
        arr[i].start = start[i];
        arr[i].pos = i + 1;
    }
    // sort arr[] according to end time
    sort(arr, arr + n, [](meet &a, meet &b)
         { return a.end < b.end; });
    int limit = arr[0].end;
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].start > limit)
        {
            count++;
            limit = arr[i].end;
        }
        

    }
    return count;
}
int main()
{
   int start[] = {10, 12, 20}, end[] = {20, 25, 30};
   int n = 3;
   int ans = maxMeetings(start,end,n);
   cout << ans << endl;

    return 0;
}