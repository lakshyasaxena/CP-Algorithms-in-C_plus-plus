#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//  Initially you are given a matrix of N rows and M columns having 0 in all blocks.
//  Then you are given Q queries
//  each query has following
//  x1,y1,x2,y2,value
//
//  for each query you have to update the matrix from index (x1,y1)  to  (x2,y2)  with value
//  Note: You have to only update the blocks lying within the rectangle formed between (x1,y1) to (x2,y2)
//
//  Then print the updated matrix
//
//  consider the following example
//  0 0 0 0 0                                      0 0 0 0 0
//  0 0 0 0 0                                      0 5 5 5 0
//  0 0 0 0 0  ->  (1,1) to (3,3) update by 5  ->  0 5 5 5 0
//  0 0 0 0 0                                      0 5 5 5 0
//  0 0 0 0 0                                      0 0 0 0 0
//
//  Like this you have to perform Q queries and update the MATRIX
//
void initialize_matrix(vector <vector <ll>> &matrix,ll n,ll m)
{
    n++;
    m++;
    for(int i=0;i<n;i++)
    {
        vector <ll> v1(m,0);
        matrix.push_back(v1);
    }
}
void traverse(vector <vector <ll>> &matrix,ll n,ll m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void prifix_sum(vector <vector <ll>> &matrix,ll n,ll m)
{
    n++;m++;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            matrix[i][j]+=matrix[i][j-1];
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            matrix[j][i]+=matrix[j-1][i];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,m;
    cout<<"Enter the number of Rows and Columns\n";
    cin>>n>>m;
    vector <vector <ll>> matrix;
    initialize_matrix(matrix,n,m);
    traverse(matrix,n,m);
    ll queries;
    cout<<"Enter the number of queries\n";
    cin>>queries;
    cout<<"Enter x1 y1 x2 y2 value\n";
    while(queries--)
    {
        ll x1,y1,x2,y2,value;
        cin>>x1>>y1>>x2>>y2>>value;
        matrix[x1][y1]+=value;
        matrix[x2+1][y1]-=value;
        matrix[x1][y2+1]-=value;
        matrix[x2+1][y2+1]+=value;
    }
    cout<<"\nAfter updation\n\n";
    prifix_sum(matrix,n,m);
    traverse(matrix,n,m);
    return 0;
}
