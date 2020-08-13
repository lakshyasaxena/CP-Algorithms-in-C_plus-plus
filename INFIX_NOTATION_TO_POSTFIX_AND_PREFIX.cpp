
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string infix_to_postfix(string a)
{
    string postfix;
    int index=-1;
    a+=")";
    stack <char> operators;
    operators.push('(');
    while(operators.size()!=0)
    {
        char choice=a[++index];
        switch (choice)
            {
            case '^':    // power operator
                {
                    while(1)
                    {
                        if(operators.top()=='^')
                        {
                            postfix+=operators.top();
                            operators.pop();
                        }
                        else
                            break;
                    }
                    operators.push('^');
                    break;
                }
            case '*':
            case '/':
                {
                    while(1)
                    {
                        if(operators.top()=='^'||operators.top()=='*'||operators.top()=='/')
                        {
                            postfix+=operators.top();
                            operators.pop();
                        }
                        else
                            break;
                    }
                    operators.push(a[index]);
                    break;
                }
            case '+':
            case '-':
                {
                    while(1)
                    {
                        if(operators.top()=='^'||operators.top()=='*'||operators.top()=='/'||operators.top()=='+'||operators.top()=='-')
                        {
                            postfix+=operators.top();
                            operators.pop();
                        }
                        else
                            break;
                    }
                    operators.push(a[index]);
                    break;
                }
            case '(':
                {
                    operators.push('(');
                    break;
                }
            case ')':
                {
                    while(operators.top()!='(')
                    {
                        postfix+=operators.top();
                        operators.pop();
                    }
                    operators.pop();
                    break;
                }
            default:
                {
                    postfix+=a[index];
                    break;
                }
            }
    }
    return postfix;
}
void solve_bracket_issue(string &a)
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='(') {a[i]=')'; continue;}
        if(a[i]==')') {a[i]='('; continue;}
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    string infix="A+(B*C-(D/E^F)*G)*H";
    cout<<"Infix notation   -> "<<infix<<"\n";
    cout<<"Postfix notation -> "<<infix_to_postfix(infix)<<"\n";
    string prefix=infix;
    reverse(prefix.begin(),prefix.end());
    solve_bracket_issue(prefix);
    prefix=infix_to_postfix(prefix);
    reverse(prefix.begin(),prefix.end());
    cout<<"Prefix notation  -> "<<prefix<<"\n";
    return 0;
}
