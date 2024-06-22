#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<bits/stdc++.h>
#include"LinkedList.h"

using namespace std;
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
    // delete node->next;

        
    }
    
int main(){
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);
    deleteNode(head->next);
    while(head!=NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    return 0;
}