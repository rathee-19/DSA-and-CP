#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include "LinkedList.h"

using namespace std;

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    if (list1->val > list2->val)
    {
        swap(list1, list2);
    }
    ListNode *temp = list1;  // Initialize temp properly
    ListNode *res = list1;

    while (list1 && list2)
    {
        cout << list1->val << " " << list2->val << endl;           
        if (list1 == NULL || list2 == NULL)
        {
            break;
        }
        if(list1->val > list2->val)
        {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
        else
        {
            cout << "Here" << endl;
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
    }

    // Connect the remaining part
    if (list1)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }

    return res;
}
int main()
{
    ListNode *head1 = new ListNode();
    head1->val = 1;
    head1->next = new ListNode();
    head1->next->val = 10;
    head1->next->next = new ListNode();
    head1->next->next->val = 12;
    head1->next->next->next = NULL;

    ListNode *head2 = new ListNode();
    head2->val = 2;
    head2->next = new ListNode();
    head2->next->val = 3;
    head2->next->next = new ListNode();
    head2->next->next->val = 5;
    head2->next->next->next = NULL;

    ListNode *ans = mergeTwoLists(head1, head2);
    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}