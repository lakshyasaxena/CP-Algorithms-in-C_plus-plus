#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void permute(ll low,ll up,string &str,vector <string> &permutations)
{
    if(low==up)  // base case
    {
        permutations.push_back(str); return ;
    }
    for(int i=low;i<=up;i++)
    {
        swap(str[low],str[i]);
        permute(low+1,up,str,permutations);
        // backtrack
        swap(str[low],str[i]);
    }
}
vector<string> build_permutations(string &str)
{
    vector <string> permutations;
    ll low=0;
    ll up=str.size()-1;
    permute(low,up,str,permutations);
    return permutations;
}
void traverse(vector <string> &v1)
{
    cout<<"PERMUTATIONS ARE\n";
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    string str="abc";
    cout<<"String is -> "<<str<<"\n";
    vector <string> permutations;
    permutations=build_permutations(str);
    traverse(permutations);
    return 0;
}
