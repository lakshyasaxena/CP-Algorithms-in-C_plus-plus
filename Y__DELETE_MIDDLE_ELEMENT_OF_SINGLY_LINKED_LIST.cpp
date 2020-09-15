#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//
//   Given a Singly Linked List
//   You have to delete the middle node from it
//
//    Note: You can encounter with two of the cases
//    case 1: When you have odd number of nodes
//            In this case you simply have to delete the middle node
//
//    case 2: When you have even number of nodes
//             In this case you have two middle nodes, you have to delete the right one
//
//
//   Consider following example for your reference
//
//    head -> 2 -> 10 -> 20 -> 25 -> 100
//    After Deleting Middle node  (Odd case)
//    head -> 2 -> 10 -> 25 -> 100
//    After Deleting Middle node  (Even case)
//    head -> 2 -> 10 -> 100
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
lis* delete_middle_node(lis *head)
{
    if(head==NULL)  // case 1: List is empty
    {
        cout<<"List is empty, No middle value, Nothing to delete \n\n";
        return head;
    }
    if(head->next==NULL)  // case 2: Last node to be deleted, here we also update head
    {
        cout<<"Middle Node value = "<<head->data<<"  , Deleting it\n\n";
        delete(head);
        head=NULL;
        return head;
    }
    lis* slow=head;
    lis* fast=head;
    lis *pre=NULL;

    while(fast!=NULL &&  fast->next != NULL)
    {
        fast=fast->next->next;
        pre=slow;
        slow=slow->next;
    }
    cout<<"Middle Node value = "<<slow->data<<"  , Deleting it\n\n";
    pre->next=slow->next;
    delete(slow);
    return head;

}
//************************************************************************************************************
int main()
{
    lis *head=NULL;
    fill_list(head);

    traverse_list(head);

    head = delete_middle_node(head);

    traverse_list(head);

    head = delete_middle_node(head);

    traverse_list(head);

    head = delete_middle_node(head);

    traverse_list(head);

    head = delete_middle_node(head);

    traverse_list(head);

    head = delete_middle_node(head);

    traverse_list(head);

    head = delete_middle_node(head);

    traverse_list(head);

    return 0;
}




// this below function has nothing do to with delete middle function
void fill_list(lis *&head)
{
    insert_in_front_of_list(head,10);
    insert_in_front_of_list(head,20);
    insert_in_front_of_list(head,25);
    insert_in_front_of_list(head,40);
    insert_in_front_of_list(head,50);
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

