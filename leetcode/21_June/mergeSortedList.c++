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

    // Ensure list1 starts with the smaller value
    if (list1->val > list2->val)
    {
        swap(list1, list2);
    }

    ListNode *res = list1; // The head of the merged list

    while (list1 != NULL && list2 != NULL)
    {
        ListNode *temp = NULL; // Temporary node for swapping

        // Find the position to insert list2's current node
        while (list1 != NULL && list1->val <= list2->val)
        {
            temp = list1;
            list1 = list1->next;
        }

        // Link the node from list2 into the merged list
        temp->next = list2;

        // Swap list1 and list2 to keep the smallest element in list1
        swap(list1, list2);
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