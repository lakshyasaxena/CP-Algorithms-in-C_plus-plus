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
    ll x,y,A,B,m;
    cout<<"Enter the value of A m and B\n";
    cin>>A>>m>>B;
    ll d=gcd(A,m,x,y);
    if((B%d!=0)||(B>=m)||d!=1)
    {
        cout<<"Can not be solved by this method\n";
        return 0;
    }
    x=(x+m)%m;  // to solve the issue of negative modulo
    ll ans=(B*x)%m;
    cout<<"put x ="<<ans<<"\n";
    cout<<"("<<A<<"*"<<ans<<") % "<<m<<" = "<<B<<"\n";
    return 0;
}
void mm(void)
{
    cout<<"Linear Congruence Equation\n\n";
    cout<<"Suppose we have :\n\n";
    cout<<"  (A * X) % m = b    (here % stands for modulo operation)\n";
    cout<<"In this, we have to find the value of X which satisfies the equation\n";
    cout<<"Note : A solution will exist only if -> B is divisible by GCD(A,m)\n\n";
    cout<<"Example :\n";
    cout<<"  (7 * x) % 11 = 4\n";
    cout<<" In this put x = 10\n\n";


}
