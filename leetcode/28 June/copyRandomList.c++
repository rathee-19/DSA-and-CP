#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;
Node *copyList(Node *head)
{
    Node *temp = head;

    Node *copy = new Node(temp->val);
    Node *start = copy;

    while (temp->next != NULL)
    {
        temp = temp->next;
        Node *Next = new Node(temp->val);
        // copy->val = temp->val;
        copy->next = Next;
        copy = Next;
    }
    temp = head;
    Node* temp2 = NULL ;
    temp2->next = start;
     while(temp->next!= NULL){
        temp2->random = temp->random ;
        


    }

    return start;
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

    Node *ans = copyList(head);
    while (ans != NULL)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }

    return 0;
}