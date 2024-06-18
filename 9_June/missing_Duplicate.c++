#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;
    
    int* repeatedNumber(const int* A, int n1, int *len1) {
        int *result = (int*)malloc(2*sizeof(long long int));
        long long int sn1 = (n1*(n1+1))/2;
        long long int sn2 = (n1*(n1+1)*(2*n1+1))/6;
        long long int sum1 =0;
        long long int sum2 =0;
        int i;
        for ( i = 0; i < n1; i++)
        {
            sum1 += A[i];
            sum2 += (long long int)A[i]*(long long int)A[i];
        }
        long long int diff1 = sn1 - sum1;
        long long int diff2 = sn2 - sum2;
         diff2 = diff2/diff1;
        result[1] = (diff1+diff2)/2;
        result[0] = (diff2-diff1)/2;
        


        return result;
}

int main(){
    int arr[] = {3, 1, 2, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *len1;
    int *result = repeatedNumber(arr, n, len1);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}