#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//  This is a Knapsack problem using the greedy approach
//  Consider the below data to check the algorithm
//   Weight of BAG = 15
//
//   Object  ->  1   2   3   4   5   6   7
//   Profit  ->  10  5   15  7   6   18  3
//   Weight  ->  2   3   5   7   1   4   1
//
//  You have to fill the bag with weights such that profit is maximum.
//  Note: You can also add weights into the bag in a fraction
//
//
void traverse(priority_queue <tuple <float,ll,ll>> pq)
{
    while(!pq.empty())
    {
        cout<<get<0>(pq.top())<<" "<<get<1>(pq.top())<<" "<<get<2>(pq.top())<<"\n";
        pq.pop();
    }
}
float knapsack(priority_queue <tuple <float,ll,ll>> &pq,ll bag)
{
    float profit=0;
    while(!pq.empty() && bag!=0)
    {
        if(get<2>(pq.top())<=bag)
        {
            bag-=get<2>(pq.top());
            profit+=float(get<1>(pq.top()));
        }
        else
        {
            float fraction=float(bag)/float(get<2>(pq.top()));
            profit+=fraction*float(get<1>(pq.top()));
            bag=0;
        }
        pq.pop();
    }
    return profit;
}
int main()
{
    ios_base::sync_with_stdio(false);
    std::cout<< std::fixed;
    std::cout<< std::setprecision(6);
    ll bag_weight=15;
    ll number_of_objects=7;
    priority_queue <tuple <float,ll,ll>> pq;
    // use below code to have your own input
    /*
    cin>>bag_weight>>number_of_objects;
    for(int i=0;i<number_of_objects;i++)
    {
        ll p,w;
        cin>>p>>w;
        float f1=float(p)/float(w);
        pq.push(make_tuple(f1,p,w));
    }
    */
    pq.push(make_tuple(float(10)/float(2),10,2));
    pq.push(make_tuple(float(5)/float(3),5,3));
    pq.push(make_tuple(float(15)/float(5),15,5));
    pq.push(make_tuple(float(7)/float(7),7,7));
    pq.push(make_tuple(float(6)/float(1),6,1));
    pq.push(make_tuple(float(18)/float(4),18,4));
    pq.push(make_tuple(float(3)/float(1),3,1));
    cout<<"Input data\n";
    traverse(pq);
    float profit=knapsack(pq,bag_weight);
    cout<<"Maximum profit = "<<profit<<"\n";
    return 0;

}

