#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//    Given some Singly Link List
//    You have to delete if it has a cycle in it.
//
//    Consider the following List for reference
//
//     List 1:
//    (head1)-> 10 -> 20 -> 30 -> 50 -> 80
//                    ^                   \_
//                    |                     100
//                    |                      |
//                    |                      |
//                   500<------ 300<--------200
//
//
//        Cycle detected in list,  after removing the cycle
//
//    (head1)-> 10 -> 20 -> 30 -> 50 -> 80 -> 100 -> 200 -> 300 -> 500 -> NULL
//
//     List 2:
//    (head2)-> 10 -> 20 -> 30 -> 50 -> 100 -> 500 -> NULL
//
//        No Cycle detected in list
//
//     List 3:
//     (head3)-> 7---->|
//               ^     |
//               |_____|
//
//        Cycle detected in list,  after removing the cycle
//
//     (head3)-> 7---> NULL
//
//      List 4:
//     (head4)-> 12---->NULL
//
//        No Cycle detected in list
//
//
class Singly_Linked_List_Node
{
public:
    ll data;
    Singly_Linked_List_Node *next=NULL;
};
typedef Singly_Linked_List_Node lis;
void insert_in_front(lis *&,ll);
void traverse(lis *);
void fill_list4(lis *&);
void fill_list3(lis *&);
void fill_list2(lis *&);
void fill_list1(lis *&);

//********************************************************************************************************************
void print_cycle(lis *head)
{
    cout<<"Cycle detected as -> ";
    lis *head2=head;
    do
    {
        cout<<head2->data<<" ";
        head2=head2->next;
    }
    while(head!=head2);
    cout<<"\n";
}
//************************************************************************************************************************************
void delete_cycle_from_list(lis *head,lis *fast)
{
    while( head->next != fast->next )
    {
        head=head->next;
        fast=fast->next;
    }
    fast->next=NULL;
}
bool detect_cycle_in_singly_linked_list(lis *head)
{
    if(head==NULL )  // there is no node in list
    {
        return false;
    }
    lis *slow=head;
    lis *fast=head;
    while(slow  &&  fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            print_cycle(fast);
            delete_cycle_from_list(head,fast);
            cout<<"Cycle removed \n";
            return true;
        }
    }
    return false;
}
//************************************************************************************************************************************
int main()
{
    lis *head1=NULL;
    lis *head2=NULL;
    lis *head3=NULL;
    lis *head4=NULL;
    fill_list1(head1);
    fill_list2(head2);
    fill_list3(head3);
    fill_list4(head4);

    cout<<"Processing List 1\n";
    bool f=detect_cycle_in_singly_linked_list(head1);
    if(f==false) cout<<"No cycle detected\n";
    traverse(head1);

    cout<<"\nProcessing List 2\n";
    f=detect_cycle_in_singly_linked_list(head2);
    if(f==false) cout<<"No cycle detected\n";
    traverse(head2);

    cout<<"\nProcessing List 3\n";
    f=detect_cycle_in_singly_linked_list(head3);
    if(f==false) cout<<"No cycle detected\n";
    traverse(head3);

    cout<<"\nProcessing List 4\n";
    f=detect_cycle_in_singly_linked_list(head4);
    if(f==false) cout<<"No cycle detected\n";
    traverse(head4);

    return 0;
}



void insert_in_front(lis *&head,ll num)
{
    lis *temp=new(lis);
    temp->data=num;
    if(head==NULL)  // first node is inserted
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}

void traverse(lis *head)
{
    cout<<"List is as follow: { ";
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<" }\n\n";
}
void fill_list1(lis *&head)
{
    insert_in_front(head,500);
    lis *store=head;
    insert_in_front(head,300);
    insert_in_front(head,200);
    insert_in_front(head,100);
    insert_in_front(head,80);
    insert_in_front(head,50);
    insert_in_front(head,30);
    insert_in_front(head,20);
    store->next=head;  // this is to form cycle
    insert_in_front(head,10);
}
void fill_list2(lis *&head)
{
    insert_in_front(head,500);
    insert_in_front(head,100);
    insert_in_front(head,50);
    insert_in_front(head,30);
    insert_in_front(head,20);
    insert_in_front(head,10);
}
void fill_list3(lis *&head)
{
    insert_in_front(head,7);
    head->next=head;
}
void fill_list4(lis *&head)
{
    insert_in_front(head,12);
}
