#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//    You have to implement a stack using Linked List
//
//    You will be implementing three major functions in it with respective time complexity
//
//    1. Push in Stack       O(1)
//    2. Pop from Stack      O(1)
//    3. Print top of Stack  O(1)
//
//   The idea is to implement list in reverse fashion such that your head always point to last node
//   Example:
//   top_of_stack = head-> 20 -> 30 -> 40
//
class Singly_Linked_List_Node
{
public:
    ll data;
    Singly_Linked_List_Node *next=NULL;
};
typedef Singly_Linked_List_Node lis;
void traverse_stack_made_of_linked_list(lis *);


//******************************************************************************************************
void push_in_stack_made_of_linked_list(lis *&head,ll number)
{
    lis *temp=new(lis);
    temp->data=number;
    temp->next=head;
    head=temp;
}
void pop_from_stack_made_of_linked_list(lis *&head)
{
    if(head==NULL)
    {
        if(head==NULL) cout<<"Stack is empty, nothing to delete\n";
        return;
    }
    lis *temp=head;
    head=head->next;
    delete(temp);
}

void print_top_of_stack_made_of_linked_list(lis *head)
{
    if(head==NULL) cout<<"Stack is empty\n";
    else cout<<"Stack top = "<<head->data<<"\n";
    return;
}
//******************************************************************************************************
int main()
{
    lis *head=NULL;
    pop_from_stack_made_of_linked_list(head);

    push_in_stack_made_of_linked_list(head,10);
    push_in_stack_made_of_linked_list(head,20);
    push_in_stack_made_of_linked_list(head,30);

    print_top_of_stack_made_of_linked_list(head);

    traverse_stack_made_of_linked_list(head);

    pop_from_stack_made_of_linked_list(head);

    print_top_of_stack_made_of_linked_list(head);

    traverse_stack_made_of_linked_list(head);
    return 0;
}

void traverse_stack_made_of_linked_list(lis *head)
{
    cout<<"Stack elements -> { ";
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<" }\n";
}
