#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dimensions(ll n);
void build_tree(ll* arr,ll* tree,ll start,ll end,ll current);
ll get_sum(ll* tree,ll start,ll end,ll qs,ll qe);
ll get_valid_sum(ll* tree,ll start,ll end,ll qs,ll qe,ll current);
void  update(ll* arr,ll* tree,ll start,ll end,ll value,ll pos);
void update_valid(ll* tree,ll start,ll end,ll diff,ll pos,ll current);
ll dimensions(ll n)
{
    // height of segment tree is x
    ll x=ceil(log2(n));
    // number of nodes in segment tree is y
    ll y=2*pow(2,x);
    return y;
}
void build_tree(ll* arr,ll* tree,ll start,ll end,ll current)
{
    // base case
    if(start==end)
    {
        tree[current]=arr[start];
        return;
    }
    ll mid=(start+end)/2;
    build_tree(arr,tree,start,mid,current*2);
    build_tree(arr,tree,mid+1,end,current*2+1);
    tree[current]=tree[current*2]+tree[current*2+1];
}
void traverse(ll* tree,ll N)
{
    cout<<"    Current tree node values\n";
    for(auto i=1;i<N;i++)
    {
        cout<<"["<<"("<<i<<") "<<tree[i]<<"] ";
    }
    cout<<"\n\n";
}
void traverse_arr(ll* arr,ll n)
{
    cout<<"    Current Array\n [ ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<" ]\n\n";
}
ll get_sum(ll* tree,ll start,ll end,ll qs,ll qe)
{
    if(qs<start||qe>end||qs>qe)
    {
        cout<<"INVALID CHOICE\n";
        return -1;
    }
    return get_valid_sum(tree,start,end,qs,qe,1);
}
ll get_valid_sum(ll* tree,ll start,ll end,ll qs,ll qe,ll current)
{
    //case 1: complete overlap
    if(qs<=start&&end<=qe)  return tree[current];
    // case 2: no overlaps
    if(end<qs||start>qe) return 0;
    //case 3 partial overlaps
    ll mid=(start+end)/2;
    return (get_valid_sum(tree,start,mid,qs,qe,current*2)+get_valid_sum(tree,mid+1,end,qs,qe,current*2+1));
}
void  update(ll* arr,ll* tree,ll start,ll end,ll value,ll pos)
{
    if(pos<start||pos>end)
    {
        cout<<"INVALID CHOICE\n";
        return;
    }
    ll diff=value-arr[pos];
    arr[pos]=value;
    update_valid(tree,start,end,diff,pos,1);
}
void update_valid(ll* tree,ll start,ll end,ll diff,ll pos,ll current)
{
    if(pos<start||pos>end) return;
    tree[current]+=diff;
    if(start!=end)
    {
        ll mid=(start+end)/2;
        update_valid(tree,start,mid,diff,pos,current*2);
        update_valid(tree,mid+1,end,diff,pos,current*2+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll arr[]={1,2,3,4,5};
    traverse_arr(arr,5);
    ll n,N,i;
    n=sizeof(arr)/sizeof(arr[0]);
    N=dimensions(n);
    ll tree[N];
    for(i=0;i<N;i++) tree[i]=0;
    build_tree(arr,tree,0,n-1,1);
    traverse(tree,N);
    ll value,pos;
    value=10;
    pos=2;
    cout<<"Update index "<<pos<<" by value "<<value<<" in array\n";
    update(arr,tree,0,n-1,value,pos);
    traverse_arr(arr,5);
    traverse(tree,N);
    cout<<"***********************************************************\n";
    ll qs,qe,store;
    qs=1;
    qe=3;
    cout<<"Get sum form index range "<<qs<<" to "<<qe<<"\n";
    store=get_sum(tree,0,n-1,qs,qe);
    cout<<"The sum is = "<<store<<"\n";
    cout<<"\n  Through Segment tree, you can perform Updates in Array with LOG(n) complexity\n";
    cout<<"\n  And  range  sum  queries  can perform  with LOG(n) complexity\n";
    return 0;
}
