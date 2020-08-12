#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll power(ll &a,ll b);
int main()
{
    ll a=10,b=18;
    cout<<power(a,b);
    return 0;
}
ll power(ll &a,ll b)
{
    if(b==0) return 1;
    ll half=power(a,b/2);
    ll ret=half*half;
    if(b&1==1) ret*=a;
    return ret;
}
