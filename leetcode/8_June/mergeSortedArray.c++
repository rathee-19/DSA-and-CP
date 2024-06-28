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
        return;
    }
    if (n == 0)
    {
        return;
    }
    for (int i = 0; i <= m; i++)
    {
        if (b >= n)
        {
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
    }
}

// shell sort gap method
void merge1(vector<int> &num1, int m, vector<int> &num2, int n)
{
    if (m == 0)
    {
        num1 = num2;
    }
    if (n == 0)
    {
        return;
    }
    int len = m + n;
    int gap = (len / 2) + (len % 2);
    while (gap > 0)
    {
        int a = 0;
        int b = gap;
        while (b < len)
        {
            if (a < m && b >= m)
            {
                if (num1[a] > num2[b - m])
                {
                    swap(num1[a], num2[b - m]);
                }
            }
            else if (a >= m)
            {
                if (num2[a - m] > num2[b - m])
                {
                    swap(num2[a - m], num2[b - m]);
                }
            }
            else
            {
                if (num1[a] > num1[b])
                {
                    swap(num1[a], num1[b]);
                }
            }
            a++, b++;
        }
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }
}

int main()
{
    vector<int> nums1 = {4, 5, 6, 0, 0, 0};
    vector<int> nums2 = {1, 2, 3};
    merge1(nums1, 3, nums2, 3);
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }

    return 0;
}