#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//
//   Given a Singly Linked List
//   You have to make a function to reverse it in O(n) time complexity
//   Note: You also need to update the head pointer of the List
//
//   Consider following example for your reference
//
//    head -> 2 -> 10 -> 20 -> 25 -> 100
//    Reverse the List
//    head -> 100 -> 25 -> 20 -> 10 -> 2
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
void reverse_list(lis *&head)
{
    lis *pre=NULL;
    lis *curr=head;
    while(curr!=NULL)
    {
        head=curr;
        curr=curr->next;
        head->next=pre;
        pre=head;
    }
}
//************************************************************************************************************
int main()
{
    lis *head=NULL;
    fill_list(head);

    traverse_list(head);

    reverse_list(head);
    cout<<"\nAfter reversing the List\n\n";

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
    cout<<"List is as follows { ";
    while(!head==NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<" } \n";
}
