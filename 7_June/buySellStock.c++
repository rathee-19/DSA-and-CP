#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
int maxProfit(vector<int> &prices)
{

    int buy = prices[0];
    int profit = 0;
    int cost;
    for (int i = 1; i < prices.size(); i++)

    {
        cost = prices[i] - buy;
        profit = max(profit, cost);
        buy = min(buy, prices[i ]);

    }
    // if (profit < 0 )   //  reading the solution after 10 days, I realized that this is not needed
    //     return 0;                 
    return profit;
}
int main()
{
    vector<int> prices = {2,1,4};
    cout << maxProfit(prices) << endl;

    return 0;
}