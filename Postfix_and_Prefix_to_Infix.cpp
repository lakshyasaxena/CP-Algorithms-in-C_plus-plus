#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string postfix_to_infix(string a)
{
    int index=-1;
    stack <string> infix;
    while(index!=a.size()-1)
    {
        char choice=a[++index];
        switch(choice)
            {
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                {
                    string c1=infix.top();
                    infix.pop();
                    string c2=infix.top();
                    infix.pop();
                    string store="(";
                    store+=c2;
                    store+=choice;
                    store+=c1;
                    store+=")";
                    infix.push(store);
                    break;
                }
            default:
                {
                    string c1="";
                    c1+=choice;
                    infix.push(c1);
                    break;
                }
            }
    }
    return infix.top();
}
string prefix_to_infix(string a)
{
    reverse(a.begin(),a.end());
    int index=-1;
    stack <string> infix;
    while(index!=a.size()-1)
    {
        char choice=a[++index];
        switch(choice)
            {
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                {
                    string c1=infix.top();
                    infix.pop();
                    string c2=infix.top();
                    infix.pop();
                    string store="(";
                    store+=c1;
                    store+=choice;
                    store+=c2;
                    store+=")";
                    infix.push(store);
                    break;
                }
            default:
                {
                    string c1="";
                    c1+=choice;
                    infix.push(c1);
                    break;
                }
            }
    }
    return infix.top();
}
int main()
{
    ios_base::sync_with_stdio(false);
    string postfix="AB*C+";
    cout<<"Postfix Notation -> "<<postfix<<"\n";
    cout<<"Infix   Notation -> "<<postfix_to_infix(postfix)<<"\n\n";
    string prefix="*+AB-CD";
    cout<<"Prefix Notation -> "<<prefix<<"\n";
    cout<<"Infix   Notation -> "<<prefix_to_infix(prefix)<<"\n\n";
    return 0;
}
