#include<bits/stdc++.h>

using namespace std;
int findDuplicate(vector < int > & nums) {
  int slow = nums[0];
  int fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  fast = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}
void FindDuplicate(vector<int> & nums){
    int curr= 0;
    int next= nums[0];
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     curr = nums[curr];
    //     next = nums[nums[next]];
    //     cout << next<< "" << endl;
    //     if (curr == next)
    //     {
    //         // cout << "The duplicate element is " << curr << endl;

    //         break;
    //     }
    // }
    while (curr != next)
    {
        curr = nums[curr];
        next = nums[nums[next]];
        if (curr == next)
        {
            cout << "The duplicate element is " << curr << endl;
            break;
        }
        
    }
    cout << "coming here";
    next = 0;
    while (curr != next)
    {
        curr = nums[curr];
        next = nums[next];
        if (curr == next)
        {
            cout << "The duplicate element is " << curr << endl;
            break;
        }
        
    }
    
    
    
}
void FindDuplicate1(vector<int> & nums) {
    int slow = nums[0];
    int fast = nums[nums[0]];
    
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    
    // Find the entrance to the cycle
    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
        
    }
    
    cout << "The duplicate element is " << slow << endl;
}

int main() {
  vector < int > arr;
  arr = {1,3,4,2,1};
  FindDuplicate1(arr);

//   cout << "The duplicate element is " << findDuplicate(arr) << endl;
}
