#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void mm(void);
vector <ll> only_one_prime(ll num)
{
    vector <ll> only_one_prime_out_of_all;
    if(num%2==0)
    {
        while(num%2==0) num/=2;
        only_one_prime_out_of_all.push_back(2);
    }
    for(int i=3;i<=sqrt(num);i+=2)
    {
        if(num%i==0)
        {
            while(num%i==0) num/=i;
            only_one_prime_out_of_all.push_back(i);
        }
    }
    if(num>1) only_one_prime_out_of_all.push_back(num);
    return only_one_prime_out_of_all;
}
ll euler_totient_function(ll num)
{
    vector <ll> unique_prime=only_one_prime(num);
    ll store=num;
    for(int i=0;i<unique_prime.size();i++)
    {
        store*=(unique_prime[i]-1);
    }
    for(int i=0;i<unique_prime.size();i++)
    {
        store/=(unique_prime[i]);
    }
    return store;
}
int main()
{
    ios_base::sync_with_stdio(false);
    mm();
    cout<<"Enter the number -> ";
    ll num;
    cin>>num;
    cout<<"Phi = "<<euler_totient_function(num)<<"\n";
    return 0;
}
void mm(void)
{
    cout<<"EULER TOTIENT FUNCTION / PHI FUNCTION\n";
    cout<<"This function counts the positive integers less than N, which are co-prime to N\n";
    cout<<"Two numbers are co-prime if their GCD is 1\n\n";
    cout<<"Example :\n";
    cout<<"Phi (7) = {1,2,3,4,5,6}  =>   Phi(7) = 6 \n";
    cout<<"Phi(6) = {1,5}           =>   Phi(6) = 2 \n\n";
    cout<<"Note: If N is a prime number, Phi(N) = (N-1)\n\n\n";
}
