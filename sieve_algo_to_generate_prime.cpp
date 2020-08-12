
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <ll> store_prime(ll num)
{
    vector <bool> status(num,0);
    vector <ll> prime_numbers;
    if(num>=2) prime_numbers.push_back(2);
    for(int i=3;i<=num;i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i;j<=num;j+=i)
            {
                status[j]=1;
            }
            prime_numbers.push_back(i);
        }
    }
    return prime_numbers;
}
void traverse(vector <ll> &prime)
{
    cout<<" Prime numbers are -\n";
    for(int i=0;i<prime.size();i++)
    {
        cout<<prime[i]<<" \n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout<<"Enter the upper bound -> ";
    ll num;
    cin>>num;
    vector <ll> prime_numbers;
    prime_numbers=store_prime(num);
    traverse(prime_numbers);
    return 0;
}
