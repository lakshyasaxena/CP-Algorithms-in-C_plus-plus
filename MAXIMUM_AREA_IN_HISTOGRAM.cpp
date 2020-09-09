#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
//
//    Find the largest rectangular area possible in a given histogram where the largest
//    rectangle can be made of a number of contiguous bars. For simplicity, assume that
//    all bars have same width and the width is 1 unit.
//
//    For example, consider the following histogram with 7 bars of heights
//    {6, 2, 5, 4, 5, 1, 6}. The area of largest possible rectangle is 12 units
//
//
//
//
//              [ ]                           [ ]
//              [ ]       [ ]       [ ]       [ ]
//              [ ]       [ ]  [ ]  [ ]       [ ]                              [ ] [ ] [ ]
//              [ ]       [ ]  [ ]  [ ]       [ ]     ------------------->     [ ] [ ] [ ]
//              [ ]  [ ]  [ ]  [ ]  [ ]       [ ]       Largest Area in        [ ] [ ] [ ]  = 12 units
//              [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]        histogram is          [ ] [ ] [ ]
//      Arr = [  6    2    5    4    5    1    6  ]                             5   4   5
//
//

void traverse(vector <ll> &v1)
{
    cout<<"Bar heights are as follows : \n";
    for(int i=1;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll i,num,n;
    vector <ll> bar_heights;
    bar_heights.pb(0);   // index 0 represent nothing
    bar_heights.pb(6);   // index 1
    bar_heights.pb(2);   // index 2
    bar_heights.pb(5);   // index 3
    bar_heights.pb(4);   // index 4
    bar_heights.pb(5);   // index 5
    bar_heights.pb(1);   // index 6
    bar_heights.pb(6);   // index 7

        ll max_area=0,area;
        n=7;
        pair <ll,ll> pp1,pp2;
        stack <pair <ll,ll > > s1;
        for(i=1;i<=n;i++)
        {
            num=bar_heights[i];
            pp2=make_pair(i,num);
            if(i==1)  // first element of bar
            {
                s1.push(pp2);
                max_area=pp2.second;
                continue;
            }

            pp1=s1.top();
            if(pp2.second>=pp1.second)
            {
                s1.push(pp2);
            }
            else
            {
                while(!s1.empty())
                {
                    pp1=s1.top();
                    if(pp2.second>=pp1.second) {break;}
                    s1.pop();
                    if(s1.size()==0)
                    {
                        area=pp1.second*(i-1);
                        //cout<<"on empty stack area= "<<area<<"\n";
                        max_area=max(max_area,area);
                    }
                    else
                    {
                        area=pp1.second*(i-s1.top().first-1);
                        //cout<<"area = "<<area<<"\n";
                        max_area=max(max_area,area);
                    }
                }
                s1.push(pp2);
            }
        }

        while(!s1.empty())
        {
            pp1=s1.top();
            s1.pop();
             if(s1.size()==0)
                    {
                        area=pp1.second*(i-1);
                        //cout<<"on empty stack area= "<<area<<"\n";
                        max_area=max(max_area,area);
                    }
                    else
                    {
                        area=pp1.second*(i-s1.top().first-1);
                        //cout<<"area = "<<area<<"\n";
                        max_area=max(max_area,area);
                    }
        }
        traverse(bar_heights);
        cout<<"Maximum rectangular area = ";
        cout<<max_area<<"\n";
    return 0;
}
