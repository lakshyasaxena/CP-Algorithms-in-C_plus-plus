#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//  Given a Singly Link List
//  You have to perform three types of delete operation
//
//  1. Delete from front
//  2. Delete from back
//  3. Delete node by value
//
//  Note: Singly Linked List should also maintain the two types of pointers
//         a - head pointer
//         b - tail pointer
//
class Singly_Linked_List_Node
{
public:
    ll data;
    Singly_Linked_List_Node *next=NULL;
};
typedef Singly_Linked_List_Node lis;
void insert_in_front(lis *&,lis *&,ll);
void traverse(lis *);


//********************************************************************************************************************
void delete_in_front(lis *&head,lis *&tail)  // Note: these parameters are reference pointers, not ordinary pointer
{
    if(head==NULL)
    {
        cout<<"List is empty\n";
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
void delete_in_last(lis *&head,lis *&tail)
{
    if(head==NULL)
    {
        cout<<"List is empty\n";
    }
    if(head==tail) // last node to be deleted
    {
        delete(head);
        head=tail=NULL;
    }
    else
    {
        lis *head2=head;
        while(head2->next->next!=NULL)
        {
            head2=head2->next;
        }
        tail=head2;
        lis *temp=head2->next;
        head2->next=NULL;
        delete(temp);
    }
}
void delete_by_value(lis *&head,lis *&tail,ll value)
{
    if(head==NULL)
    {
        cout<<"List is Empty\n";
        return;
    }
    else if(head->data==value) // if head node is supposed to be deleted
    {
        delete_in_front(head,tail);
        return;
    }
    else
    {
        lis *head2=head;    // it is a temporarily head
        while(head2->next!=NULL)    // searching for first appearance of node
        {
            if(head2->next->data==value)  // node found
            {
                if(head2->next == tail)  // last node to be deleted
                {
                    lis *temp=head2->next;
                    head2->next=NULL;
                    tail=head2;
                    delete(temp);
                    return;
                }
                else
                {
                    lis *temp=head2->next;
                    head2->next=head2->next->next;
                    delete(temp);
                    return;
                }
            }
            head2=head2->next;
        }
    }
    cout<<"Node value not found\n";
}
//********************************************************************************************************************
int main()
{
    lis *head=NULL;
    lis *tail=NULL;

    insert_in_front(head,tail,100);
    insert_in_front(head,tail,7);
    insert_in_front(head,tail,10);
    insert_in_front(head,tail,5);
    insert_in_front(head,tail,1);
    insert_in_front(head,tail,50);

    traverse(head);

    cout<<"Delete from first\n";
    delete_in_front(head,tail);
    traverse(head);

    cout<<"Delete from last\n";
    delete_in_last(head,tail);
    traverse(head);

    cout<<"Delete by value from List, value = 10\n";
    delete_by_value(head,tail,10);
    traverse(head);

    cout<<"Delete by value from List, value = 10\n";
    delete_by_value(head,tail,10);
    traverse(head);

    cout<<"Delete by value from List, value = 1\n";
    delete_by_value(head,tail,1);
    traverse(head);

    cout<<"Delete by value from List, value = 5\n";
    delete_by_value(head,tail,5);
    traverse(head);

    cout<<"Delete by value from List, value = 7\n";
    delete_by_value(head,tail,7);
    traverse(head);

    return 0;
}


void insert_in_front(lis *&head,lis *&tail,ll num)
{
    lis *temp=new(lis);
    temp->data=num;
    if(head==NULL)  // first node is inserted
    {
        head=tail=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}

void traverse(lis *head)
{
    cout<<"List is as follows: { ";
    while(!head==NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<" }\n\n";
}
