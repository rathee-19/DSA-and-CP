#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
int solve(int *A, int n1, int B)
{
    // Your code here
    unordered_map<int, int> mpp;
    int maxi = 0;
    int Xor = 0;
    for (int i = 0; i < n1; i++)
    {
        Xor = Xor ^ A[i];
        // cout<< Xor << endl ;
        if (Xor == B)
        {
            maxi++;
        }

        if (mpp.find(Xor ^ B) != mpp.end())
        {

            maxi = maxi + mpp[Xor ^ B];
        }

        mpp[Xor]++;
    }

    return maxi;
}
int main()
{
    int A[] = {4,2,2,6,4};
    int n = sizeof(A) / sizeof(A[0]);
    cout << solve(A, n, 6) << endl;
   

    return 0;
}