#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//  Given a Singly Linked List
//  You have to determine if it is a Palindromic Linked List or not
//  This solution is using N space complexity [ (N/2) nodes are being stored in stack  ]
//  The idea is very simple, We will maintain a stack and store nodes in it till half traverse
//  Then we will pop the nodes from stack  and compare with nodes with the remaining Nodes of List traversal
//
//  Example:
//       head1 -> 10 -> 20 -> 30 -> 30 -> 20 -> 10
//              It is a palindromic linked list
//
//       head2 -> 10 -> 20 -> 20
//               It is not a palindromic linked list
//
class Singly_Linked_List_Node
{
public:
    ll data;
    Singly_Linked_List_Node *next=NULL;
};
typedef Singly_Linked_List_Node lis;
void insert_in_front_of_list(lis *&,ll);
void traverse(lis *);
void fill_list1_(lis *&);
void fill_list2_(lis *&);
void fill_list3_(lis *&);
void fill_list4_(lis *&);
void fill_list5_(lis *&);

//***********************************************************************************************
bool check_for_palindrome_with_n_space_complexity(lis *head)
{
    if(head==NULL) return false;
    stack <lis*> s;
    lis *slow=head;
    lis* fast=head;
    while(fast && fast->next)
    {
        s.push(slow);
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast==NULL)  // Even Case  ( when length of List is even )
    {
        while(slow)
        {
            if(slow->data != s.top()->data ) return false;
            s.pop();
            slow=slow->next;
        }
    }
    else           // odd case   ( when length of List is odd )
    {
        slow=slow->next;
        while(slow)
        {
            if(slow->data != s.top()->data ) return false;
            s.pop();
            slow=slow->next;
        }
    }
    return true;
}
//***********************************************************************************************
int main()
{
    lis *head1=NULL;
    lis *head2=NULL;
    lis *head3=NULL;
    lis *head4=NULL;
    lis *head5=NULL;
    lis *head6=NULL;

    cout<<"List1 ";
    fill_list1_(head1);
    traverse(head1);

    cout<<"List2 ";
    fill_list2_(head2);
    traverse(head2);

    cout<<"List3 ";
    fill_list3_(head3);
    traverse(head3);

    cout<<"List4 ";
    fill_list4_(head4);
    traverse(head4);

    cout<<"List5 ";
    fill_list5_(head5);
    traverse(head5);

    cout<<"List6 ";
    traverse(head6);

    cout<<"\n\n";
    bool f=check_for_palindrome_with_n_space_complexity(head1);
    cout<<"List1 is ";
    (f==true)?cout<<" a Palindromic Linked List\n":cout<<" not a Palindromic Linked List\n";

    f=check_for_palindrome_with_n_space_complexity(head2);
    cout<<"List2 is ";
    (f==true)?cout<<" a Palindromic Linked List\n":cout<<" not a Palindromic Linked List\n";

    f=check_for_palindrome_with_n_space_complexity(head3);
    cout<<"List3 is ";
    (f==true)?cout<<" a Palindromic Linked List\n":cout<<" not a Palindromic Linked List\n";

    f=check_for_palindrome_with_n_space_complexity(head4);
    cout<<"List4 is ";
    (f==true)?cout<<" a Palindromic Linked List\n":cout<<" not a Palindromic Linked List\n";

    f=check_for_palindrome_with_n_space_complexity(head5);
    cout<<"List5 is ";
    (f==true)?cout<<" a Palindromic Linked List\n":cout<<" not a Palindromic Linked List\n";

    f=check_for_palindrome_with_n_space_complexity(head6);
    cout<<"List6 is ";
    (f==true)?cout<<" a Palindromic Linked List\n":cout<<" not a Palindromic Linked List\n";

    return 0;
}




void fill_list1_(lis *&head)
{
    insert_in_front_of_list(head,10);
    insert_in_front_of_list(head,20);
    insert_in_front_of_list(head,30);
    insert_in_front_of_list(head,40);
    insert_in_front_of_list(head,30);
    insert_in_front_of_list(head,20);
    insert_in_front_of_list(head,10);
}

void fill_list2_(lis *&head)
{
    insert_in_front_of_list(head,10);
    insert_in_front_of_list(head,20);
    insert_in_front_of_list(head,30);
    insert_in_front_of_list(head,30);
    insert_in_front_of_list(head,20);
    insert_in_front_of_list(head,10);
}

void fill_list3_(lis *&head)
{
    insert_in_front_of_list(head,10);
    insert_in_front_of_list(head,20);
    insert_in_front_of_list(head,30);
    insert_in_front_of_list(head,30);
    insert_in_front_of_list(head,20);
}

void fill_list4_(lis *&head)
{
    insert_in_front_of_list(head,10);
}

void fill_list5_(lis *&head)
{
    insert_in_front_of_list(head,10);
    insert_in_front_of_list(head,20);
    insert_in_front_of_list(head,20);
    insert_in_front_of_list(head,20);
}

void insert_in_front_of_list(lis *&head,ll value)
{
    lis *temp=new(lis);
    temp->data=value;
    if(head==NULL) // first node is inserted
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
    cout<<"{ ";
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"}\n";
}
