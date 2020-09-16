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
ll find_nth_node_from_end_in_singly_linked_list(lis *head,ll n)
{
    lis *slow=head;
    lis *fast=head;
    while(n--)
    {
        fast=fast->next;
    }
    while(fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow->data;
}
//*****************************************************************************************************
int main()
{
    lis *head=NULL;

    insert_in_front_of_singly_linked_list(head,50);
    insert_in_front_of_singly_linked_list(head,40);
    insert_in_front_of_singly_linked_list(head,30);
    insert_in_front_of_singly_linked_list(head,30);
    insert_in_front_of_singly_linked_list(head,20);
    insert_in_front_of_singly_linked_list(head,10);

    traverse_singly_linked_list(head);

    ll Nth=2;  // we expect that Nth value is a valid node from end (Out of bounds condition should never exist)
    ll node=find_nth_node_from_end_in_singly_linked_list(head,Nth);
    cout<<"\n"<<Nth<<"nd node from end is = "<<node<<"\n";

    Nth=1;
    node=find_nth_node_from_end_in_singly_linked_list(head,Nth);
    cout<<"\n"<<Nth<<"st node from end is = "<<node<<"\n";

    Nth=6;
    node=find_nth_node_from_end_in_singly_linked_list(head,Nth);
    cout<<"\n"<<Nth<<"th node from end is = "<<node<<"\n";

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

