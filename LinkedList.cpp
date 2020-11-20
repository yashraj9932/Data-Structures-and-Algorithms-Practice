//Linked List Operations
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void createList(int n);
void insertAtEnd(int x);
void deleteNode();
void insertAtBeginning(int x);
void print();
void reverseList();
void printRecur(Node *t);
void printReverse(Node *t);
void reverseListRecur(Node *t);

Node *start;

int main()
{
    start = NULL;
    cout << "Enter the value of n:" << endl;
    int n;
    cin >> n;
    createList(n);
    // deleteNode();
    // reverseList();
    reverseListRecur(start);
    print();
    return 0;
}
void createList(int n)
{
    cout << "Enter the numbers:" << endl;
    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node();
        Node *last;
        cin >> temp->data;
        temp->next = NULL;
        if (start == NULL)
            start = temp;
        else
            last->next = temp;
        last = temp;
    }
    print();
    // printRecur(start);
    // printReverse(start);
}
void insertAtBeginning(int x)
{
    Node *t1 = new Node();
    t1->data = x;
    t1->next = start;
    start = t1;
}
void print()
{
    Node *temp = start;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void insertAtEnd(int x)
{
    if (start == NULL)
        insertAtBeginning(x);
    else
    {
        Node *t = new Node();
        t->data = x;
        t->next = NULL;
        Node *t1 = start;
        while (t1->next != NULL)
            t1 = t1->next;
        t1->next = t;
    }
}
void deleteNode()
{
    cout << "Enter the position of node to delete" << endl;
    int pos;
    cin >> pos;
    if (pos <= 0)
        cout << "Invalid position.Are you an Idiot?Will have to terminate! :(" << endl;
    else if (pos == 1)
        start = start->next;
    else
    {
        int i = 1;
        Node *temp = start;
        while (true)
        {
            i++;
            if (i == pos)
                break;
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
    print();
}
void reverseList()
{
    Node *prev = NULL;
    Node *curr = start;
    Node *t;//Declaring a temporary pointer
    while (curr != NULL)
    {
        t = curr->next;//Storing value of next pointer temporarily
        curr->next = prev;//Storing the adress of previous node initially to now as the next node of the initially the next node.
        prev = curr;//Storing the present curr as the previos node which will help in next iteration
        curr = t;//Storing the next node as curr for moving curr forward
    }
    start = prev;//Lastly the adress of the last last node is put into the start pointer.
    print();
}

//Printing values with recursion
//The Value is printed and the next link is passed,it prints till it gets the base case where it return; and the function terminates.
void printRecur(Node *t)
{
    if (t == NULL)//Base Case
    {
        cout << endl;
        return;
    }
    else
    {
        cout << t->data << " ";
        printRecur(t->next);
    }
}

//Printing the value of node in reverse
/*First the address of next nodes is sent continuously,because of this the print operation
is still left to print in each function in the function call stack and since the topmost thing 
is exeuted first,the list is printed in reverse order.*/
void printReverse(Node *t)
{
    if (t == NULL)//Base Case
        return;
    else
    {
        printReverse(t->next);
        cout << t->data << " ";
    }
}

//Reversal Using Recursion
/*Continuously the links of the nodes are passed down first till the last node is reached(because of 
this some part of each function call is left out),when the last node is reached,the address of start is updated,
after this ,just the nodes are interchanged(in adrress)and the values of addresses and pointers adjusted
and after this process is completed ,the list is reversed.*/
void reverseListRecur(Node *t)
{
    if (t->next == NULL)//Base or Last Case
    {
        start = t;
        return;
    }
    reverseListRecur(t->next);
    t->next->next = t;//current node ka next ka next pointer is made equal to current(reverse ho ja rha) and then
    t->next = NULL;//current ko null
}
