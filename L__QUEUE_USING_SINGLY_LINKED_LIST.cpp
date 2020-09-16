#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//    You have to implement a Queue using Linked List
//
//    You will be implementing four major functions in it with respective time complexity
//
//    1. Push in Queue         O(1)
//    2. Pop from Queue        O(1)
//    3. Print front of queue  O(1)
//    4. Print rear of  queue  O(1)
//
//   The idea is that we will maintain head and tail both pointer in the List
//
class Singly_Linked_List_Node
{
public:
    ll data;
    Singly_Linked_List_Node *next=NULL;
};
typedef Singly_Linked_List_Node lis;
void traverse_queue_made_of_linked_list(lis *);
//*****************************************************************************************************************
void push_in_queue_made_of_linked_list(lis *&head,lis *&tail,ll number)
{
    lis *temp=new(lis);
    temp->data=number;
    if(tail==NULL) // firs node to be inserted
    {
        head=tail=temp;
    }
    else    // List already has some nodes
    {
        tail->next=temp;
        tail=temp;
    }
}
void pop_in_queue_made_of_linked_list(lis *&head,lis *&tail)
{
    if(head==NULL)
    {
        cout<<"Queue is empty , nothing to delete\n";
    }
    else if(head==tail) // last node to be deleted
    {
        delete(head);
        head=tail=NULL;
    }
    else
    {
        lis *temp=head;
        head=head->next;
        delete(temp);
    }
}
void print_front_element(lis *head)
{
    if(head==NULL) cout<<"Queue is empty\n";
    else cout<<"Front element = "<<head->data<<"\n";
}
void print_rear_element(lis *tail)
{
    if(tail==NULL) cout<<"Queue is empty\n";
    else cout<<"Rear element = "<<tail->data<<"\n";
}
//*****************************************************************************************************************
int main()
{
    lis *head=NULL;  // here head represent front of queue
    lis *tail=NULL;  // here head represent rear  of queue

    cout<<"push 10\n";
    push_in_queue_made_of_linked_list(head,tail,10);
    cout<<"push 20\n";
    push_in_queue_made_of_linked_list(head,tail,20);
    cout<<"push 30\n";
    push_in_queue_made_of_linked_list(head,tail,30);

    print_front_element(head);
    print_rear_element(tail);

    traverse_queue_made_of_linked_list(head);
    cout<<"pop from front \n";
    pop_in_queue_made_of_linked_list(head,tail);

    traverse_queue_made_of_linked_list(head);
    cout<<"pop from front \n";
    pop_in_queue_made_of_linked_list(head,tail);

    traverse_queue_made_of_linked_list(head);
    cout<<"pop from front \n";
    pop_in_queue_made_of_linked_list(head,tail);

    traverse_queue_made_of_linked_list(head);
    cout<<"pop from front \n";
    pop_in_queue_made_of_linked_list(head,tail);
    return 0;
}


void traverse_queue_made_of_linked_list(lis *head)
{
    cout<<"Queue : { ";
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"}\n";
}

