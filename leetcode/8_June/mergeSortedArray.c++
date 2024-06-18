#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    int a = 0;
    int b = 0;
    if (m == 0)
    {
        nums1 = nums2;
    }
    if (n == 0)
    {
        return;
    }
    for (int i = 0; i <=m ; i++)
    {
        cout << "a: " << a << " b: " << b << "value 1: "<< nums1[a]<< "value 2: "<< nums2[b]<< endl;
        if (b >= n)
        {
            cout<<"came here";
            break;
        }
        
        if (nums1[a] > nums2[b] || a >= m)
        {
            nums1.insert(nums1.begin() + i, nums2[b]);
            nums1.pop_back();
            b++;
            a++;
            m++;
            

        }
      
        else
        {

            a++;
        }
        // if (a >= m) {
        //     nums1[i] = nums2[b++];
        // } else if (b < n && nums1[a] > nums2[b]) {
        //     nums1.insert(nums1.begin() + i, nums2[b++]);
        //     nums1.pop_back();
        // } else {
        //     a++;
        // }
    
    }
}
int main()
{
    vector<int> nums1 = {4,5,6,0,0,0};
    vector<int> nums2 = {1,2,3};
    merge(nums1, 3, nums2, 3);
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }

    return 0;
}