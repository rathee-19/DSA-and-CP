// my_structs.h
#ifndef LinkedList_H
#define LinkedList_H

struct Node
{
   int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};



#endif // MY_STRUCTS_H
