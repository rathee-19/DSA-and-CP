#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;
Node *copyRandomList(Node *head)
{
    Node *dummy = new Node(0);
    Node *curr = head;
    Node *head3 = dummy;
    unordered_map<Node *, Node *> m;
    while (curr)
    {
        Node *n = new Node(curr->val);
        head3->next = n;
        m[curr] = n;
        curr = curr->next;
        head3 = head3->next;
    }
    curr = head;
    head3 = dummy->next;

    while (curr)
    {
        Node *value = curr->random;
        if (value != NULL)
        {
            head3->random = m[value];
        }
        else
        {
            head3->random = NULL;
        }
        head3 = head3->next;
        curr = curr->next;
    }

    return dummy->next;
}

int main()
{
    Node *head = new Node(0);
    // head->val = 0;
    head->next = new Node(1);
    // head->next->val = 1;
    head->next->next = new Node(2);
    // head->next->next->val = 2;
    head->next->next->next = NULL;

    Node *ans = copyRandomList(head);
    while (ans != NULL)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }

    return 0;
}