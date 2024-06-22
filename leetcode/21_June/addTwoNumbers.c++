#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include "LinkedList.h"

using namespace std;
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode();
    ListNode *temp = dummy;
    int carry = 0;
    while (l1 || l2 || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;
        ListNode *node = new ListNode(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next;
}
int main()
{
    ListNode *head1 = new ListNode();
    head1->val = 1;
    head1->next = new ListNode();
    head1->next->val = 2;
    head1->next->next = new ListNode();
    head1->next->next->val = 3;
    head1->next->next->next = NULL;

    ListNode *head2 = new ListNode();
    head2->val = 4;
    head2->next = new ListNode();
    head2->next->val = 5;

    ListNode *ans = addTwoNumbers(head1, head2);
    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}