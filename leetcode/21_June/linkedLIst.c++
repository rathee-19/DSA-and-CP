#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *convertArrayToLinkedList(vector<int> arr)
{
    Node *head = new Node();
    head->data = arr[0];
    head->next = NULL;
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node();
        newNode->data = arr[i];
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;

        /* code */
    }

    return head;
}

Node *removeHead(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *removeTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}
Node *removeK(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (k == 1)
    {
        head = removeHead(head);
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    int count = 0;
    while (temp)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node *removeValue(Node *head, int val)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->data == val)
    {
        cout << "why bro" << head->data << endl;

        head = removeHead(head);
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp)
    {
        if (temp->data == val)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node *insertHead(Node *head, int val)
{
    if (head == NULL)
    {
        head->data = val;
        return head;
    }
    Node *temp = new Node;
    temp->data = val;
    temp->next = head;
    head = temp;
    return head;
}
Node *insertTail(Node *head, int val)
{
    if (head == NULL)
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        return newNode;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    temp->next = newNode;
    return head;
}
Node *insertK(Node *head, int k, int val)
{
    if (head == NULL)
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        return newNode;
    }
    if (k == 1)
    {
        return insertHead(head, val);
    }
    Node *temp = head;
    int count = 0;
    while (temp->next)
    {
        count++;
        if ((count + 1) == k)
        {
            Node *newNode = new Node;
            newNode->data = val;
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
Node *convert(vector<int> &arr)
{
    Node *head = new Node();
    head->data = arr[0];
    head->next = NULL;
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node();
        newNode->data = arr[i];
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }

    head = removeHead(head);
    head = removeTail(head);
    head = removeK(head, 1);

    head = removeValue(head, 3);

    head = insertHead(head, 9);
    head = insertTail(head, 19);
    head = insertK(head, 1, 24);
    cout << head->data << endl;
    Node *trav = head;
    int length = 0;

    while (trav)
    {

        cout << trav->data << " ";
        trav = trav->next;
        length++;
    }
    cout << endl
         << "legth " << length << " ";
    return head;
}
bool serach(Node *head, int target)
{

    Node *temp = head;
    while (temp)
    {
        if (temp->data == target)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
int main()
{
    Node *head = new Node();
    head->data = 1;
    head->next = new Node();
    head->next->data = 2;
    head->next->next = new Node();
    head->next->next->data = 3;
    head->next->next->next = new Node();
    head->next->next->next->data = 4;
    head->next->next->next->next = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head2 = convert(arr);
    bool ans = serach(head, 6);
    cout << ans << endl;

    return 0;
}