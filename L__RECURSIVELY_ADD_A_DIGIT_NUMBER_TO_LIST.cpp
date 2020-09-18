#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//
//   A number is represented is the form of Singly Linked List with head pointing the left most digit
//
//   You have to add a One Digit number to this List
//   And for that you have to make a recursive function
//
//
//   Consider following example for your reference
//
//    head -> 9 -> 9 -> 9 -> 9 -> 9
//    add 9 to it
//    head -> 1 -> 0 -> 0 -> 0 -> 0 -> 8
//
class Singly_Linked_List_Node
{
public:
    ll data;
    Singly_Linked_List_Node *next=NULL;
};
typedef Singly_Linked_List_Node lis;
void fill_list1(lis *&);
void fill_list2(lis *&);
void insert_in_front_of_list(lis *&,ll);
void traverse_list(lis *);
//************************************************************************************************************
ll add_number_from_last_recursively(lis *head,ll n)
{
    if(!head->next)  // we have reached the last node
    {
        head->data+=n;
        if(head->data < 10) // no carry generated
        {
            return 0;
        }
        else
        {
            n=head->data/10;
            head->data%=10;
            return n;
        }
    }

    ll carry=add_number_from_last_recursively(head->next,n);

    if(carry==0) return 0; // no carry was generated

    head->data+=carry;

    if(head->data < 10) // no carry generated
    {
        return 0;
    }
    else
    {
        carry=head->data/10;
        head->data%=10;
        return carry;
    }
}
lis* add_number_two_singly_linked_list(lis *head,ll n)
{
    ll carry=add_number_from_last_recursively(head,n);

    if(carry==0)  // no carry generated
    {
        return head;
    }
    else  // carry generated, we need to add an additional node and update head
    {
        lis *temp=new(lis);
        temp->data=carry;
        temp->next=head;
        head=temp;
        return head;
    }
}
//************************************************************************************************************
int main()
{
    lis *head1=NULL;
    fill_list1(head1);

    cout<<"List1 is \n";
    traverse_list(head1);

    cout<<"\nAdd 9 to it\n\n";

    head1=add_number_two_singly_linked_list(head1,9);

    cout<<"List1 is \n";
    traverse_list(head1);

    cout<<"\n";

    lis *head2=NULL;
    fill_list2(head2);

    cout<<"List2 is \n";
    traverse_list(head2);

    cout<<"\nAdd 9 to it\n\n";

    head2=add_number_two_singly_linked_list(head2,9);

    cout<<"List2 is \n";
    traverse_list(head2);


    return 0;
}
// this below function has nothing do to with reverse function
void fill_list1(lis *&head)
{
    insert_in_front_of_list(head,9);
    insert_in_front_of_list(head,9);
    insert_in_front_of_list(head,9);
    insert_in_front_of_list(head,9);
    insert_in_front_of_list(head,9);
}
void fill_list2(lis *&head)
{
    insert_in_front_of_list(head,9);
    insert_in_front_of_list(head,9);
    insert_in_front_of_list(head,5);
    insert_in_front_of_list(head,6);
    insert_in_front_of_list(head,1);
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
    cout<<"[ ";
    while(!head==NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<" ] \n";
}

