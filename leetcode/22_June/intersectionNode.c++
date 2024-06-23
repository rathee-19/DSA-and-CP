#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include "LinkedList.h"

using namespace std;
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

  if (!headA || !headB) return NULL;

    ListNode *a = headA;
    ListNode *b = headB;
    int l1 = 0;
    int l2 = 0;

    // Calculate the length of the first list
    while (a) {
        l1++;
        a = a->next;
    }

    // Calculate the length of the second list
    while (b) {
        l2++;
        b = b->next;
    }

    int dif = abs(l1 - l2);
    a = headA;
    b = headB;

    // Advance the pointer of the longer list by the difference in lengths
    if (l1 > l2) {
        for (int i = 0; i < dif; i++) {
            a = a->next;
        }
    } else {
        for (int i = 0; i < dif; i++) {
            b = b->next;
        }
    }

    // Move both pointers until they point to the same node
    while (a && b) {
        if (a == b) {
            return a;
        }
        a = a->next;
        b = b->next;
    }

    return NULL;
    }
int main()
{
    ListNode *head1 = new ListNode(4);
    head1->next = new ListNode(1);
    head1->next->next = new ListNode(8);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    ListNode *head2 = new ListNode(5);
    head2->next = new ListNode(0);

    head2->next->next = new ListNode(1);
    head2->next->next->next = head1->next->next;

    ListNode *ans = getIntersectionNode(head1, head2);
    cout << ans->val << endl;

    return 0;
}