#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Singly_Linked_List_Node
{
public:
    ll data;
    Singly_Linked_List_Node *next;
};
typedef Singly_Linked_List_Node lis;
void insert_in_front_of_singly_linked_list(lis *&,ll);
void traverse_singly_linked_list(lis *);

//********************************************************************************************************************
void delete_it_from_list(lis *&head,lis *pre)
{
    if(pre==NULL) // first node is to be deleted
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

void delete_last_appreance_of_element_form_list(lis *&head,ll value)
{
    if(head==NULL) {cout<<"\nList is empty\n";return;}
    lis *store=NULL;
    lis *curr=head;
    lis *pre=NULL;

    while(curr)
    {
        if(curr->data==value)
        {
            pre=store;
        }
        store=curr;
        curr=curr->next;
    }
    if(pre==NULL  &&  head->data !=value)
    {
        cout<<"No such element found\n";
    }
    else
    {
        delete_it_from_list(head,pre);
        cout<<"Deleted\n\n";
    }
}
//********************************************************************************************************************
int main()
{
    lis *head=NULL;

    insert_in_front_of_singly_linked_list(head,30);
    insert_in_front_of_singly_linked_list(head,20);
    insert_in_front_of_singly_linked_list(head,10);
    insert_in_front_of_singly_linked_list(head,50);
    insert_in_front_of_singly_linked_list(head,20);
    insert_in_front_of_singly_linked_list(head,10);
    insert_in_front_of_singly_linked_list(head,10);
    insert_in_front_of_singly_linked_list(head,20);
    insert_in_front_of_singly_linked_list(head,30);

    traverse_singly_linked_list(head);

    cout<<"\n\nDelete last appearance of 100\n";
    delete_last_appreance_of_element_form_list(head,100);

    cout<<"\n\nDelete last appearance of 20\n";
    delete_last_appreance_of_element_form_list(head,20);

    traverse_singly_linked_list(head);

    cout<<"\n\nDelete last appearance of 30\n";
    delete_last_appreance_of_element_form_list(head,30);

    traverse_singly_linked_list(head);

    cout<<"\n\nDelete last appearance of 30\n";
    delete_last_appreance_of_element_form_list(head,30);

    traverse_singly_linked_list(head);
}




void insert_in_front_of_singly_linked_list(lis *&head,ll value)
{
    lis *temp=new(lis);
    temp->data=value;
    if(head==NULL) // first node
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
    cout<<"LIST: {";
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"}";
}
