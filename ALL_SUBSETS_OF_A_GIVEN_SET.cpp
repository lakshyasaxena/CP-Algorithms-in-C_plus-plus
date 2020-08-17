#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Given a set
//  Find all possible subsets of it
//  Example : set = {1,2}
//  Subsets are:
//  {}
//  {1}
//  {1,2}
//  {2}
//
//  Number of subsets = 2 to the power n, where n is the number of elements in the set.
//  Time Complexity is O(2^N)
//
void build_subsets_recursively(vector <ll> &current_set,vector <vector <ll>> &all_sets, vector <ll> &array,ll index)
{
    all_sets.push_back(current_set);
    for(int i=index;i<array.size();i++)
    {
        current_set.push_back(array[i]);
        build_subsets_recursively(current_set,all_sets,array,i+1);
        // backtrack
        current_set.pop_back();
    }
}
vector <vector <ll>> build_subsets(vector <ll> &array)
{
    vector <ll> current_set;
    vector <vector <ll>> all_sets;
    ll index=0;
    build_subsets_recursively(current_set,all_sets,array,index);
    return all_sets;
}
void traverse(vector <vector <ll>> &v1)
{
    cout<<"SUBSETS ARE\n";
    for(int i=0;i<v1.size();i++)
    {
        cout<<"{";
        for(int j=0;j<v1[i].size();j++)
        {
            cout<<v1[i][j]<<" ";
        }
        cout<<"}\n";
    }
    cout<<"\n";
}
void traverse(vector <ll> &array)
{
    cout<<"ARRAY ELEMENTS ARE\n";
    for(int i=0;i<array.size();i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    vector <ll> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    traverse(array);
    vector <vector <ll>> subsets;
    subsets=build_subsets(array);
    traverse(subsets);
    return 0;
}
