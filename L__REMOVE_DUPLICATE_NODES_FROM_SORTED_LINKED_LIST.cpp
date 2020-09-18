#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//
//   Given a Singly Sorted Linked List with some Duplicate Node values
//   You have to delete the duplicate node values from it and List should remain sorted
//
//   Consider following example for your reference
//
//    head -> 10 -> 10 -> 20 -> 20 -> 25 -> 100 -> NULL
//    Remove duplicate node values
//    head -> 10 -> 20 -> 25 -> 100 -> NULL
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
void remove_duplicate_nodes_from_sorted_linked_list(lis *&head)
{
    if(!head) return; // no list exist

    lis* curr_head=head;
    lis* pre=NULL;

    while(curr_head->next)
    {
        if(curr_head->data == curr_head->next->data) // duplicate node
        {
            if(!pre) // first node to be deleted
            {
                lis *temp=curr_head;
                curr_head=curr_head->next;
                head=curr_head;
                delete(temp);
            }
            else
            {
                lis* temp=curr_head;
                curr_head=curr_head->next;
                pre->next=curr_head;
                delete(temp);
            }
        }
        else
        {
            pre=curr_head;
            curr_head=curr_head->next;
        }
    }
}
//************************************************************************************************************
int main()
{
    lis *head=NULL;
    fill_list(head);

    cout<<"Sorted List with duplicate node values\n";
    traverse_list(head);

    cout<<"\n\nSorted List without duplicate node values\n";
    remove_duplicate_nodes_from_sorted_linked_list(head);


    traverse_list(head);
    return 0;
}
// this below function has nothing do to with reverse function
void fill_list(lis *&head)
{
    insert_in_front_of_list(head,50);
    insert_in_front_of_list(head,50);
    insert_in_front_of_list(head,40);
    insert_in_front_of_list(head,30);
    insert_in_front_of_list(head,20);
    insert_in_front_of_list(head,20);
    insert_in_front_of_list(head,10);
    insert_in_front_of_list(head,10);
    insert_in_front_of_list(head,10);
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
    cout<<"{ ";
    while(!head==NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<" } \n";
}

