#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll power(ll &a,ll b,ll &m);
void msb(void);
int main()
{
    msb();
    cout<<"Enter the three numbers a,b,m and make sure m is prime number\n";
    ll a,b,m;
    cin>>a>>b>>m;
    a=a%b;    // basic mod property
    ll ans=power(a,b%(m-1),m);     // As per Fermat's little theorem
    cout<<"("<<a<<"^"<<b<<") % "<<m<<" = "<<ans<<"\n";
    return 0;
}
ll power(ll &a,ll b,ll &m)
{
    if(b==0) return 1;
    ll half=power(a,b/2,m);
    ll ret=(half*half)%m;
    if(b&1==1) ret=(ret*a)%m;
    return ret;
}
void msb(void)
{
    cout<<"  Fermat's Little Theorem\n";
    cout<<"If (a) to the power (b) modulo (m) is asked and (m) is a prime number then\n";
    cout<<"a to the power (m-1) % m is one\n\n";
    cout<<"(a)^(b)%m=?  , where m is prime\n";
    cout<<"hence (a)^(m-1) % m = 1\n";
    cout<<"Example\n\n";
    cout<<" (5^9) % 7\n";
    cout<<"=> (5^6 * 5^3) %7\n";
    cout<<"=> ((5^6 %7) * (5^3 %7)) % 7\n";
    cout<<"=> ((1) * (5^3 % 7) % 7\n";
    cout<<"=> 6\n\n";
}
