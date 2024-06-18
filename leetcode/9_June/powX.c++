#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;
    //mathematical approach
    double myPow(int x, int n) {
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return x;
        }
        if (n == -1)
        {
            return 1/x;
        }
        double half = myPow(x, n/2);
        double full = half * half;
        if (n % 2 == 0)
        {
            return full;
        }
        else
        {
            return n > 0 ? full * x : full * 1/x;
        }
    }
    //intuitive approach without recursion
    double MyPow(double  x, int n){
        double ans = 1;
        long long nt = n;
        if (nt < 0)
        {
            nt = -1 * nt;
            
        }
        while (nt)
        {
            if (nt % 2)
            {
                ans *= x;
                cout<<ans<<endl;
                nt--;
            }
            else
            {
                x *= x;
                nt /= 2;
            }
        }
        if(n < 0)
        {
            ans = 1/ans;
        }

        return ans;

    }

int main(){
    cout << MyPow(2.1, -2) << endl;
    return 0;
}