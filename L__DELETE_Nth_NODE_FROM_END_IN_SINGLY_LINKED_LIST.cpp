#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Singly_Linked_List_Node
{
public:
    ll data;
    Singly_Linked_List_Node *next=NULL;
};
typedef Singly_Linked_List_Node lis;
void insert_in_front_of_singly_linked_list(lis *&head,ll);
void traverse_singly_linked_list(lis *);
//*****************************************************************************************************
void delete_by_address_in_singly_linked_list(lis *pre,lis *&head)
{
    if(pre==NULL) // First node is to be deleted
    {
        pre=head;
        head=head->next;
        delete(pre);
    }
    else
    {
        lis *temp=pre->next;
        pre->next=pre->next->next;
        delete(temp);
    }
}
void find_nth_node_from_end_in_singly_linked_list_and_delete_it(lis *&head,ll n)
{
    lis *slow=head;
    lis *fast=head;
    lis *pre=NULL;;
    while(n--)
    {
        fast=fast->next;
    }
    while(fast)
    {
        pre=slow;
        slow=slow->next;
        fast=fast->next;
    }
    delete_by_address_in_singly_linked_list(pre,head);
    //cout<<"prev = "<<pre->data<<"\n";
    //cout<<"deleting node with value "<<slow->data;
    //delete_by_address_in_singly_linked_list(slow,head);
}
//*****************************************************************************************************
int main()
{
    lis *head=NULL;

    insert_in_front_of_singly_linked_list(head,60);
    insert_in_front_of_singly_linked_list(head,50);
    insert_in_front_of_singly_linked_list(head,40);
    insert_in_front_of_singly_linked_list(head,30);
    insert_in_front_of_singly_linked_list(head,20);
    insert_in_front_of_singly_linked_list(head,10);

    traverse_singly_linked_list(head);

    cout<<"\nDelete 3rd node from last\n";
    ll Nth=3;  // we expect that Nth value is a valid node from end (Out of bounds condition should never exist)
    find_nth_node_from_end_in_singly_linked_list_and_delete_it(head,Nth);
    traverse_singly_linked_list(head);

    cout<<"\nDelete 5th node from last\n";
    Nth=5;  // we expect that Nth value is a valid node from end (Out of bounds condition should never exist)
    find_nth_node_from_end_in_singly_linked_list_and_delete_it(head,Nth);
    traverse_singly_linked_list(head);

    cout<<"\nDelete 1st node from last\n";
    Nth=1;  // we expect that Nth value is a valid node from end (Out of bounds condition should never exist)
    find_nth_node_from_end_in_singly_linked_list_and_delete_it(head,Nth);
    traverse_singly_linked_list(head);


    return 0;
}


void insert_in_front_of_singly_linked_list(lis *&head,ll number)
{
    lis *temp=new(lis);
    temp->data=number;
    if(head==NULL) // first node in List
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}

void traverse_singly_linked_list(lis *head)
{
    cout<<"List : { ";
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"}\n";
}
