#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll power(ll a,ll b);
int main()
{
    ll a=123456789,b=987654321;
    cout<<power(a,b);  // means-> (a^b)%mod
    return 0;
}
ll power(ll a,ll b)
{
    if(b==0) return 1;
    ll half=power(a,b/2);
    ll ret=(half*half)%mod;
    if(b&1==1) ret=(ret*a)%mod;
    return ret;
}
