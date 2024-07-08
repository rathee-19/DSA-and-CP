#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int recursion(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }
    return (recursion(n - 1, k) + k) % n;
}
int findTheWinner(int n, int k)
{
    return recursion(n, k) + 1;
}
int main()
{
    int n = 5, k = 2;
    cout << findTheWinner(n, k) << endl;
    
    return 0;
}