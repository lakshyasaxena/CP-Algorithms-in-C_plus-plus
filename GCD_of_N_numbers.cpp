#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    if(a==0) return b; // base condition
    ll d=gcd(b%a,a);
    return d;
}
ll gcd_of_vector(vector <ll> &store)
{
    ll d=gcd(store[0],store[1]);
    for(int i=2;i<store.size();i++)
    {
        d=gcd(d,store[i]);
    }
    return d;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout<<"How many numbers are there ? \n";
    ll num; cin>>num;
    cout<<"Enter your numbers\n";
    vector <ll> store(num);
    for(int i=0;i<num;i++)
    {
        cin>>store[i];
    }
    ll g_c_d=gcd_of_vector(store);
    cout<<"GCD of these numbers is "<<g_c_d<<"\n";
    return 0;
}
