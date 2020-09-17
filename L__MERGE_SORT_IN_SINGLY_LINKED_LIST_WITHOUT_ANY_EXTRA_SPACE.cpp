#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//  Given a Unsorted Singly Linked List
//  You have to Sort the the List using Merge Sort
//  Note: You can not use any extra space ( in terms of making duplicate nodes )
//  The Algorithms should work in a way that, there is only rearrangement of the pointers
//
//   Example:
//    head -> 40 -> 30 -> 10 -> 20
//
//   After merge sort
//
//    head -> 10 -> 20 -> 30 -> 40
//
class Singly_Linked_List_Node
{
public:
    ll data;
    Singly_Linked_List_Node *next=NULL;
};
typedef Singly_Linked_List_Node lis;
void insert_at_end_of_list(lis *&,lis *&,ll);
void fill_list(lis *&,lis *&);
void traverse_list(lis *);


//******************************************************************************************************
void insert_at_last_of_two_sorted_list(lis *&head,lis *&tail,lis *node)    // O(1) time complexity
{
    if(!head)  // first node to be added
    {
        head=tail=node;
    }
    else
    {
        tail->next=node;
        tail=node;
    }
}
lis* merge_two_sorted_linked_list(lis* left_head,lis *right_head)
{
    lis *new_head=NULL;
    lis *new_tail=NULL;

    while( left_head  || right_head )
    {
        if(!left_head)  // all nodes of left_head have been added
        {
            new_tail->next=right_head;
            return new_head;
        }
        if(!right_head) // all nodes of right_head have been added
        {
            new_tail->next=left_head;
            return new_head;
        }
        if(left_head->data < right_head->data)
        {
            insert_at_last_of_two_sorted_list(new_head,new_tail,left_head);   // O(1) time complexity
            left_head=left_head->next;
        }
        else
        {
            insert_at_last_of_two_sorted_list(new_head,new_tail,right_head);   // O(1) time complexity
            right_head=right_head->next;
        }
    }
}
lis *merge_sort_on_singly_linked_list(lis *head,lis *tail)
{
    if(head==NULL) return head;    // when any empty List is passed, this function will encounter it

    if(head==tail)  // base case
    {
        head->next=NULL;
        return head;
    }
    lis *slow=head;
    lis *fast=head;

    while(fast!=tail && fast->next!=tail)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    lis* head1=head;        //  low
    lis* tail1=slow;        //  mid
    lis *head2=slow->next;  //  mid+1
    lis *tail2=tail;        //  end

    lis *left_head=merge_sort_on_singly_linked_list(head1,tail1);
    lis *right_head=merge_sort_on_singly_linked_list(head2,tail2);

    lis *new_head=merge_two_sorted_linked_list(left_head,right_head);
    return new_head;
}
//******************************************************************************************************

int main()
{
    lis *head=NULL;
    lis *tail=NULL;

    fill_list(head,tail);

    cout<<"Unsorted Singly Linked List\n";
    traverse_list(head);

    cout<<"\nAfter applying Merge Sort\n";

    cout<<"\n\nSorted Singly Linked List\n";
    head=merge_sort_on_singly_linked_list(head,tail);
    traverse_list(head);

    return 0;
}

void insert_at_end_of_list(lis *&head,lis *&tail,ll num)
{
    lis *temp=new(lis);
    temp->data=num;
    if(head==NULL)  // first node to be inserted
    {
        head=tail=temp;
    }
    else  // already some nodes are present
    {
        tail->next=temp;
        tail=temp;
    }
}

void fill_list(lis *&head,lis *&tail)
{
    insert_at_end_of_list(head,tail,60);
    insert_at_end_of_list(head,tail,50);
    insert_at_end_of_list(head,tail,40);
    insert_at_end_of_list(head,tail,20);
    insert_at_end_of_list(head,tail,30);
    insert_at_end_of_list(head,tail,10);
}
void traverse_list(lis *head)
{
    cout<<" [";
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"]\n";
}

