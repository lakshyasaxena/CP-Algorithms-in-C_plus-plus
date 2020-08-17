#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Given a tuple list of elements, each tuple has 3 elements
//  We have to sort the elements in ascending order based on the 1st element of each tuple
//  But if two elements of 1st tuple are equal then
//  We have to sort the elements in descending order based on the 2nd element of each tuple
//  But even if 2nd elements are equal then
//  Again we have to sort the list in ascending order based on the 3rd element of each tuple
//  Example - Consider this tuple list
//
//
//     3  5  2              1  5  2
//     1  5  4              1  5  3
//     2  2  2              1  5  4
//     3  5  1              1  3  1
//     3  1  3              1  3  10
//     1  5  2     --->     1  1  1
//     1  3  10             2  2  2
//     3  1  5              2  2  3
//     1  3  1              3  5  1
//     1  5  3              3  5  2
//     2  2  3              3  1  3
//     1  1  1              3  1  5
//
//
//
//
bool sort_in_my_way(vector <ll> &a,vector <ll> &b)
{
    if(a[0]==b[0] && a[1]==b[1])
    {
        return (a[2]<b[2]);
    }
    if(a[0]==b[0])
    {
        return (a[1]>b[1]);
    }
    return (a[0]<b[0]);
}
void traverse(vector <vector <ll>> v1)
{
    cout<<"VECTOR ELEMENTS\n";
    for(int i=0;i<v1.size();i++)
    {
        for(int j=0;j<v1[i].size();j++)
        {
            cout<<v1[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"-------------------------";
}
int main()
{
    ios_base::sync_with_stdio(false);
    vector <vector <ll>> v1;
    vector <ll> v2;
    v2.push_back(3);v2.push_back(5);v2.push_back(2);
    v1.push_back(v2); v2.clear();
    v2.push_back(1);v2.push_back(5);v2.push_back(4);
    v1.push_back(v2); v2.clear();
    v2.push_back(2);v2.push_back(2);v2.push_back(2);
    v1.push_back(v2); v2.clear();
    v2.push_back(3);v2.push_back(5);v2.push_back(1);
    v1.push_back(v2); v2.clear();
    v2.push_back(3);v2.push_back(1);v2.push_back(3);
    v1.push_back(v2); v2.clear();
    v2.push_back(1);v2.push_back(5);v2.push_back(2);
    v1.push_back(v2); v2.clear();
    v2.push_back(1);v2.push_back(3);v2.push_back(10);
    v1.push_back(v2); v2.clear();
    v2.push_back(3);v2.push_back(1);v2.push_back(5);
    v1.push_back(v2); v2.clear();
    v2.push_back(1);v2.push_back(3);v2.push_back(1);
    v1.push_back(v2); v2.clear();
    v2.push_back(1);v2.push_back(5);v2.push_back(3);
    v1.push_back(v2); v2.clear();
    v2.push_back(2);v2.push_back(2);v2.push_back(3);
    v1.push_back(v2); v2.clear();
    v2.push_back(1);v2.push_back(1);v2.push_back(1);
    v1.push_back(v2); v2.clear();
    cout<<"Before Sorting\n";
    traverse(v1);
    sort(v1.begin(),v1.end(),sort_in_my_way);
    cout<<"\nAfter Sorting in our choice\n";
    traverse(v1);
    return 0;
}
