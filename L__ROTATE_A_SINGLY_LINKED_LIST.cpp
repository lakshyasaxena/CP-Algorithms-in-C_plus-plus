#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//
//   Given a singly linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given positive integer.
//   WE can assume that k is always a valid position
//
//   Suppose if there are N nodes in Singly Linked List
//
//    then  { 0 < = k <= N  }
//
//   Consider following example for your reference
//
//    head -> 100 -> 50 -> 40 -> 25 -> 20 -> 10
//    k = 4
//    rotate counter clockwise by 4
//
//    head ->  20 -> 10 ->  100 -> 50 -> 40 -> 25
//
//
class Singly_Linked_List_Node
{
public:
    ll data;
    Singly_Linked_List_Node *next=NULL;
};
typedef Singly_Linked_List_Node lis;
void fill_list(lis *&);
void insert_in_front_of_list(lis *&,ll);
void traverse_list(lis *);
//************************************************************************************************************
void rotate_singly_linked_list(lis *&head,ll k)
{
    if(k<=0) return;  // 0 means no rotation
    lis *store=head;
    lis *pre=NULL;

    while(k--)
    {
        pre=head;
        head=head->next;
    }

    if(head==NULL)  // no rotation, we reached to last node
    {
        head=store;
        return;
    }

    pre->next=NULL;
    pre=head;

    while(pre->next)
    {
        pre=pre->next;
    }
    pre->next=store;
}
//************************************************************************************************************
int main()
{
    lis *head=NULL;
    fill_list(head);

    traverse_list(head);

    cout<<"\n Counter clockwise rotation by 4\n";

    rotate_singly_linked_list(head,4);

    traverse_list(head);

    cout<<"\n Counter clockwise rotation by 5\n";

    rotate_singly_linked_list(head,5);

    traverse_list(head);

    cout<<"\n Counter clockwise rotation by 1\n";

    rotate_singly_linked_list(head,1);

    traverse_list(head);

    cout<<"\n Counter clockwise rotation by 6\n";

    rotate_singly_linked_list(head,6);

    traverse_list(head);

    return 0;
}
// this below function has nothing do to with reverse function
void fill_list(lis *&head)
{
    insert_in_front_of_list(head,10);
    insert_in_front_of_list(head,20);
    insert_in_front_of_list(head,25);
    insert_in_front_of_list(head,40);
    insert_in_front_of_list(head,50);
    insert_in_front_of_list(head,100);
}
void insert_in_front_of_list(lis *&head,ll value)
{
    lis *temp=new(lis);
    temp->data=value;
    if(head==NULL) // first node to be inserted
    {
        head=temp;
        return;
    }
    temp->next=head;
    head=temp;
}
void traverse_list(lis *head)
{
    cout<<"\nList is as follows { ";
    while(!head==NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<" } \n";
}
