
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
# define inf 999999999999999999
void build_tree(ll* arr,ll* tree,ll start,ll end,ll current);
void traverse(ll* tree,ll N);
ll get_min(ll*tree,ll start,ll end,ll qs,ll qe);
ll get_valid_min(ll* tree,ll start,ll end,ll qs,ll qe,ll current);
void update(ll* arr,ll* tree,ll start,ll end,ll value,ll pos);
void update_valid(ll* tree,ll start,ll end,ll value,ll pos,ll current);
ll dimensions(ll n)
{
    ll x=ceil(log2(n));
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
    tree[current]=min(tree[current*2],tree[current*2+1]);
}
void traverse(ll* tree,ll N)
{
    cout<<"Tree Node structure\n";
    for(auto i=1;i<N;i++) cout<<"("<<i<<")= "<<tree[i]<<"   ";
    cout<<"\n\n";
}
void traverse_arr(ll* arr,ll n)
{
    cout<<"Current Array\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";
}
ll get_min(ll*tree,ll start,ll end,ll qs,ll qe)
{
    if(qs<start||qe>end||qs>qe)
    {
        cout<<"INVALID CHOICE\n";
        return -1;
    }
    return get_valid_min(tree,start,end,qs,qe,1);
}
ll get_valid_min(ll* tree,ll start,ll end,ll qs,ll qe,ll current)
{
    // case1 complete overlaps
    if(qs<=start&&end<=qe) return tree[current];
    // case 2 NO overlaps
    if(end<qs||start>qe) return inf;
    // case 3 partial overlaps
    ll mid=(start+end)/2;
    return min(get_valid_min(tree,start,mid,qs,qe,current*2),get_valid_min(tree,mid+1,end,qs,qe,current*2+1));
}
void update(ll* arr,ll* tree,ll start,ll end,ll value,ll pos)
{
    if(pos<start||pos>end)
    {
        cout<<"INVALID CHOICE\n";
        return;
    }
    arr[pos]=value;
    update_valid(tree,start,end,value,pos,1);
}
void update_valid(ll* tree,ll start,ll end,ll value,ll pos,ll current)
{
    if(pos<start||pos>end) return;
    if(start!=end)
    tree[current]=min(value,tree[current]);
    if(start==end) tree[current]=value;
    if(start!=end)
    {
        ll mid=(start+end)/2;
        update_valid(tree,start,mid,value,pos,current*2);
        update_valid(tree,mid+1,end,value,pos,current*2+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll arr[]={1,2,3,4};
    traverse_arr(arr,4);
    ll n,N,i;
    n=sizeof(arr)/sizeof(arr[0]);
    N=dimensions(n);
    ll tree[N];

    for(i=0;i<N;i++) tree[i]=0;
    build_tree(arr,tree,0,n-1,1);
    traverse(tree,N);
    ll value,pos;
    value =10;
    pos=1;
    cout<<"Update array at index "<<pos<<" with value = "<<value<<"\n";
    update(arr,tree,0,n-1,value,pos);
    traverse_arr(arr,4);
    traverse(tree,N);
    ll qs,qe,store;
    qs=0;
    qe=2;
    cout<<"Find minimum value in array between index "<<qs<<" to "<<qe<<"\n";
    store=get_min(tree,0,n-1,qs,qe);
    cout<<"minimum value is ="<<store<<"\n\n";
    cout<<"Note:\n";
    cout<<" Update operation in SEGMENT TREE requires LOG(n) complexity\n";
    cout<<" Finding minimum in given range also takes Log(n) complexity\n";
    return 0;
}
