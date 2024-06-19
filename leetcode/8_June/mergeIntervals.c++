#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> mergedIntervals;
    if (intervals.size() == 0)
    {
        return mergedIntervals;
    }
    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < intervals.size(); i++)
    {
        if (i == intervals.size() - 1)
        {
            mergedIntervals.push_back(intervals[i]);
            break;
        }
        if (intervals[i + 1][0] >= intervals[i][0] && intervals[i + 1][0] <= intervals[i][1])
        {
            intervals[i + 1][0] = intervals[i][0];
            intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
        }
        else
        {
            mergedIntervals.push_back(intervals[i]);
        }
    }
    return mergedIntervals;
}
vector<vector<int>> mergeSubArray(vector<vector<int>> &intervals)
{
    vector<vector<int>> mergeIntervals;
    if (intervals.size() == 0)
    {
        return intervals;
    }
    sort(intervals.begin(), intervals.end());
    int n = 0;
    // For loop for filling the mergeIntervals
    for (int i = 0; i < intervals.size(); i++)
    {
        if (mergeIntervals.empty())
        {
            mergeIntervals.push_back(intervals[i]);
        }
        else
        {
            if (intervals[i][0] <= mergeIntervals[n][1])
            {
                mergeIntervals[n][1] = max(intervals[i][1], mergeIntervals[n][1]);
            }
            else
            {
                mergeIntervals.push_back(intervals[i]);
                n++;
            }
        }
    }
    // simplifyed for loop for filling mergeIntervals
    for (int i = 0; i < intervals.size(); i++)
    {
        if (mergeIntervals.empty() || intervals[i][0] > mergeIntervals.back()[1])
        {
            mergeIntervals.push_back(intervals[i]);
        }
        else
        {
            mergeIntervals.back()[1] = max(intervals[i][1], mergeIntervals.back()[1]);
        }
    }
    return mergeIntervals;
}
vector<vector<int>> mergeRevision(vector<vector<int>> &intervals){
    vector<vector<int>> res;
    if (intervals.size()==0){
        return res;
    }
    sort(intervals.begin(),intervals.end());
    
    for (int i = 0; i < intervals.size(); i++)
    {
        if (res.empty() || intervals[i][0]>res.back()[1]){
            res.push_back(intervals[i]);
        }else{
            res.back()[1] = max(res.back()[1],intervals[i][1]);
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = mergeRevision(intervals);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}