#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
vector<int> JobScheduling(Job arr[], int n)
{
    vector<int> ans(2, 0); // Initialize with 2 elements set to 0
    if (n == 0)
    {
        return ans;
    }

    // Sort jobs in descending order of profit
    sort(arr, arr + n, [](Job &a, Job &b)
         { return a.profit > b.profit; });

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, arr[i].dead);
    }

    vector<int> slot(maxDeadline + 1, -1); // Initialize slots to -1 (indicating free slot)

    int jobCount = 0;
    int totalProfit = 0;
    cout << "comint " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = arr[i].id;
                jobCount++;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    ans[0] = jobCount;
    ans[1] = totalProfit;
    return ans;
}
int main()
{
    Job arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};   
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << n << endl;    
    vector<int> ans = JobScheduling(arr, n);
    cout << ans[0] << " " << ans[1] << endl;
    // Job Jobs[] = {(1, 4, 20), (2, 1, 10), (3, 1, 40), (4, 1, 30)};    // bhenchodddddd aadha ghanta 
    // vector<int> ans = JobScheduling(Jobs, 4);
    // cout << ans[0] << " " << ans[1] << endl;


  

    return 0;
}