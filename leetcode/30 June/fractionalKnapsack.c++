#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
struct Item
{
    int value;
    int weight;
};
double fractionalKnapsack(int w, Item arr[], int n)
{
    double ans = 0;
    sort(arr, arr + n, [](Item &a, Item &b)
         { return ((double)a.value / a.weight) > ((double)b.value / b.weight); });
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= w)
        {
            ans += arr[i].value;
            w = w - arr[i].weight;
        }
        else
        {
            ans += ((double)arr[i].value / arr[i].weight) * w;
            w = 0;
        }
        if (w == 0)
        {
            break;
        }
    }

    return ans;
}
int main()
{
    // Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    // double ans = fractionalKnapsack(50, arr, 3);
  
    Item arr[] = {{8, 10}, {2, 1}, {10, 7}, {1, 7}, {9, 5}, {7, 1}, {2, 8}, {6, 6}, {6, 4}, {8, 9}, {7, 1}};
    double ans = fractionalKnapsack(20, arr, 11);

    
    

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << arr[i].value << " " << arr[i].weight << endl;
    // }
    cout << ans << endl;
    return 0;
}
