#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//    Before looking the below code, it is advised to go through reference pointers
//    Reference Pointers are alternative of double pointers
//
//   You have to make three functions of Singly Linked List
//
//    1. Insert_at_front()                     O(1)
//    2. Insert_at_last()                      O(1)
//    3. Insert_after_value()   worst case ->  O(n)
//
//    The maximum time complexity functions can accommodate are mention
//
//    Note:
//    We will maintain two pointers
//    head_pointer -> this will point to first node of List
//    tail_pointer -> this will point to  last node of List
//
class Singly_Linked_List_Node
{
public:
    ll data;
    Singly_Linked_List_Node *next=NULL;
};
typedef Singly_Linked_List_Node lis;

//************************************************************************************************************************************
void insert_in_front(lis *&head,lis *&tail,ll num)  // Note: lis *&head , it means head is a reference pointer, not a simple pointer
{
    lis *temp=new(lis);
    temp->data=num;
    if(head==NULL)  // first node is inserted in List
    {
        head=temp;
        tail=temp;
    }
    else           // List already has some nodes in it
    {
        temp->next=head;
        head=temp;
    }
}
void insert_in_last(lis *&head,lis *&tail,ll num)
{
    lis *temp=new(lis);
    temp->data=num;
    if(head==NULL)  // first node is inserted in List
    {
        head=temp;
        tail=temp;
    }
    else           // List already has some nodes in it
    {
        tail->next=temp;
        tail=temp;
    }
}
void insert_after_value(lis *&head,lis *&tail,ll node,ll num)
{
    lis *tem_head=head;  // it is a temporary head

    while(tem_head != NULL)
    {
        if(tem_head->data==node)  // searching for first appearance of node
        {
            if(tem_head==tail)  // node found at last
            {
                insert_in_last(head,tail,num);
                return;
            }

            lis *temp=new(lis);
            temp->data=num;
            temp->next=tem_head->next;
            tem_head->next=temp;
            return;
        }
        tem_head=tem_head->next;
    }
    cout<<"Sorry Node not found\n";
}
//************************************************************************************************************************************
void traverse_list(lis *head)
{
    cout<<"The List is as follows -> { ";
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<" }\n\n";
}
int main()
{
    lis *head=NULL;   // head will point to first element in linked list
    lis *tail=NULL;   // tail will point to last  element in linked list

    cout<<"Insert at Last of List, value = 7\n";
    insert_in_last(head,tail,7);
    traverse_list(head);
    cout<<"Insert at Front of List, value = 10\n";
    insert_in_front(head,tail,10);
    traverse_list(head);
    cout<<"Insert at Front of List, value = 20\n";
    insert_in_front(head,tail,20);
    traverse_list(head);
    cout<<"Insert at Last of List, value = 30\n";
    insert_in_last(head,tail,30);
    traverse_list(head);
    cout<<"Insert at Last of List, value = 100\n";
    insert_in_last(head,tail,100);
    traverse_list(head);

    cout<<"Insert after node 7, value = 1\n";
    insert_after_value(head,tail,7,1);
    traverse_list(head);
    cout<<"Insert after node 100, value = 77\n";
    insert_after_value(head,tail,100,77);
    traverse_list(head);
    cout<<"Insert after node 200, value = 1000\n";
    insert_after_value(head,tail,200,1000);
    traverse_list(head);
    return 0;
}
