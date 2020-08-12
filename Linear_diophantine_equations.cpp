#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void mm(void);
ll gcd(ll a,ll b,ll &x,ll &y)
{
    if(a==0)
    {
        x=0;y=1;
        return b;
    }
    ll x1,y1;
    ll d=gcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}
int main()
{
    ios_base::sync_with_stdio(false);
    mm();
    cout<<"Enter the value of A B and c\n";
    ll a,b,c,x,y,d;
    cin>>a>>b>>c;
    cout<<a<<"x + "<<b<<"y = "<<c<<"\n";
    d=gcd(a,b,x,y);
    if(c%d!=0)
    {
        cout<<"Not possible to find solution\n";
        cout<<c<<" divided by GCD("<<a<<","<<b<<") is not zero\n";
        return 0;
    }
    x=(x*c)/d;
    y=(y*c)/d;
    cout<<"one of the solution is \n"<<"x="<<x<<" and y="<<y<<"\n";
    return 0;
}
void mm(void)
{
    cout<<"Linear Diophantine equation\n";
    cout<<"suppose we have \n";
    cout<<"  A*X + B*Y = C\n";
    cout<<"In this equation we have to find the values of X,Y which satisfy the equation\n";
    cout<<"\nCondition\n";
    cout<<"C should be divisible by GCD of (A and B)\n\n";
    cout<<"Example:\n";
    cout<<"  3*X + 5*Y = 21\n";
    cout<<" put X=2 and Y=3\n\n";
}
