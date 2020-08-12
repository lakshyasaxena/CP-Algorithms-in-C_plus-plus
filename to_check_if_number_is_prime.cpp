
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check_prime(ll num)
{
    if(num==1) return false;
    for(int i=2;i<=sqrt(num);i++)
    {
        if(num%i==0) return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false)
    while(1)
    {
        cout<<"Enter your number -> ";
        ll num;
        cin>>num;
        bool check=check_prime(num);
        if(check==false)
        {
            cout<<"  It is not a prime\n\n";
        }
        else
        {
            cout<<"  It is a prime number\n\n";
        }
    }
}
