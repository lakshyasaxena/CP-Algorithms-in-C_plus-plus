
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void traverse(vector <ll> &v1);
void mm(void);
vector <ll> get_prime_factors(ll num)
{
    vector <ll> store;
    while(num%2==0)
    {
        store.push_back(2);
        num/=2;
    }
    for(int i=3;i<=sqrt(num);i+=2)
    {
        while(num%i==0)
        {
            store.push_back(i);
            num/=i;
        }
    }
    if(num>1) store.push_back(num);
    return store;
}
int main()
{
    ios_base::sync_with_stdio(false);
    mm();
    cout<<"Enter the number to find it's prime factorization ->  ";
    ll num;
    cin>>num;
    vector <ll> prime_factors=get_prime_factors(num);
    traverse(prime_factors);
    return 0;
}
void traverse(vector <ll> &v1)
{
    cout<<"Prime factorization is \n";
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<"\n";
}
void mm(void)
{
    cout<<"Prime factorization\n";
    cout<<"Example :\n";
    cout<<"prime factorization of 18 = 2 * 3 * 3\n\n";
}
