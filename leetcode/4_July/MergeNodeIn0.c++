#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *mergeNodes(ListNode *head)
{
    ListNode *temp = head->next; 
    ListNode *dummy = new ListNode();
    ListNode *temp2 = dummy; 
    
    while (temp->next)
    {
        if (temp->val == 0)
        {
            
            ListNode *New = new ListNode(0);
            
            temp2->next = New;
            temp2 = New; 
            temp = temp->next;
        }
        else
        {
            temp2->val += temp->val;
            cout << dummy->val << " ";  
            
            temp = temp->next;
        }
    }
    cout << endl;
    return dummy;
}

int main()
{
    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next->next = new ListNode(0);
    head->next->next->next->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next->next->next->next->next->next = new ListNode(0);
    head->next->next->next->next->next->next->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next->next->next->next->next->next->next = new ListNode(0);
    head->next->next->next->next->next->next->next->next->next->next->next->next->next->next = NULL;
    ListNode *result = mergeNodes(head);
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}