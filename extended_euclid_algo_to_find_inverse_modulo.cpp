
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b,ll&x,ll&y)
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
    while(1)
    {
        cout<<"  Enter two numbers whose GCD is one\n";
        ll a,b,x,y,d;
        cin>>a>>b;
        d=gcd(a,b,x,y);
        if(d!=1)
        {
            cout<<"  Inverse modulo does not exits, GCD of numbers should be one\n\n";
            continue;
        }
        ll inverse=(x+b)%b;  // this step is done to avoid problem of negative modulo in c++
        cout<<"  Inverse modulo is "<<inverse<<"\n";
        cout<<"  ["<<a<<"*"<<inverse<<"] % "<<b<<" = 1\n\n";
    }
    return 0;
}
