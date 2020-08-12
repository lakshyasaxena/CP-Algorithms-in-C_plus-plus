
#include <bits/stdc++.h>
#define m 1000000007
using namespace std;
typedef long long ll;
ll fib(ll n);
bool is_prime(ll n);
void Matrix_Power(ll A[2][2], ll n);
void multiply(ll A[2][2], ll B[2][2]);
int main()
{
    ios_base::sync_with_stdio(false);
    ll num;
    cin>>num;
    cout<<fib(num);
    return 0;
}
ll fib(ll n)
{
    if(n==0) return 0;
    ll  A[2][2]={{1,1},{1,0}};
    Matrix_Power(A,n-1);
    return A[0][0];
}
void Matrix_Power(ll A[2][2], ll n)
{
    if(n==0||n==1) return;
    Matrix_Power(A,n/2);
    multiply(A,A);
    if(n%2==1) { ll B[2][2]={{1,1},{1,0}}; multiply(A,B); }
}
void multiply(ll A[2][2], ll B[2][2])
{
    ll x,y,z,w;
    x=(A[0][0]*B[0][0])+(A[0][1]*B[1][0]);
    y=(A[0][0]*B[0][1])+(A[0][1]*B[1][1]);
    z=(A[1][0]*B[0][0])+(A[1][1]*B[1][0]);
    w=(A[1][0]*B[0][1])+(A[1][1]*B[1][1]);
    A[0][0]=x;
    A[0][1]=y;
    A[1][0]=z;
    A[1][1]=w;
}
