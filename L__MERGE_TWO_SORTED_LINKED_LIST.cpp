#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//   Given two Sorted Singly Linked List
//   You have to merge them to form a new Sorted Singly Linked List
//   Note: You are not suppose to create a new List
//         You have to make changes in the arrangement of node pointers to achieve it
//         Expected time complexity is : In single traversal for both the List
//            that is O(n+k) , where n in nodes in List1 and k is nodes in List2
//
//    Example: Consider the following example for your reference
//
//   List1    head1 -> 10 -> 20 -> 30
//
//   List2    head2 -> 5 -> 15 -> 25
//
//      After merging the List
//
//   Result List    head -> 5 -> 10 -> 15 -> 20 -> 25 -> 30
//
class Singly_Linked_List_Node
{
public:
    ll data;
    Singly_Linked_List_Node *next=NULL;
};
typedef Singly_Linked_List_Node lis;
void traverse_list(lis *);
void fill_list1(lis *&);
void fill_list2(lis *&);

//*******************************************************************************************************************************
void insert_at_last_in_merged_list(lis *&head,lis *&tail,lis *node)
{
    if(!head) // first node to be inserted
    {
        head=tail=node;
    }
    else
    {
        tail->next=node;
        tail=node;
    }
}
lis* merge_two_sorted_singly_linked_list(lis *head1,lis *head2)
{
    lis *head=NULL;
    lis *tail=NULL;
    while(head1 || head2)
    {
        if(!head1)   // it means if (head==NULL)
        {
            if(!head) // List 1 is empty
            {
                head=head2;
                return head;
            }
            tail->next=head2;
            head1=head2=NULL;   // we are making them NULL because now they are of no use now
            return head;
        }
        if(!head2)
        {
            if(!head) // List 2 is empty
            {
                head=head1;
                return head;
            }
            tail->next=head1;   // we are making them NULL because now they are of no use now
            return head;
        }
        if(head1->data < head2->data)
        {
            insert_at_last_in_merged_list(head,tail,head1);
            head1=head1->next;
        }
        else
        {
            insert_at_last_in_merged_list(head,tail,head2);
            head2=head2->next;
        }
    }
    return head;
}
//*******************************************************************************************************************************
int main()
{
    lis *head1=NULL;
    lis *head2=NULL;

    cout<<"List1 ";
    fill_list1(head1);
    traverse_list(head1);

    cout<<"List2 ";
    fill_list2(head2);
    traverse_list(head2);

    cout<<"\n\nAfter merging the List : \n";
    lis *head=merge_two_sorted_singly_linked_list(head1,head2);
    traverse_list(head);


    return 0;
}

void traverse_list(lis *head)
{
    cout<<"[ ";
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"]\n";
}
void insert_in_front_of_singly_linked_list(lis *&head,ll value)
{
    lis *temp=new(lis);
    temp->data=value;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}

void fill_list1(lis*& head)
{
    insert_in_front_of_singly_linked_list(head,50);
    insert_in_front_of_singly_linked_list(head,40);
    insert_in_front_of_singly_linked_list(head,30);
    insert_in_front_of_singly_linked_list(head,20);
    insert_in_front_of_singly_linked_list(head,10);
}
void fill_list2(lis*& head)
{
    insert_in_front_of_singly_linked_list(head,65);
    insert_in_front_of_singly_linked_list(head,55);
    insert_in_front_of_singly_linked_list(head,44);
    insert_in_front_of_singly_linked_list(head,33);
    insert_in_front_of_singly_linked_list(head,18);
    insert_in_front_of_singly_linked_list(head,5);
}
