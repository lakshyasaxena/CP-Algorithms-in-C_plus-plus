#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll count_largest_square_sub_matrix(vector <vector <int>> matrix)
{
    int maxi=0;
    for(int i=0;i<matrix[0].size();i++) maxi=max(maxi,matrix[0][i]);
    for(int i=0;i<matrix.size();i++) maxi=max(maxi,matrix[i][0]);
    for(int i=1;i<matrix.size();i++)
    {
        for(int j=1;j<matrix[i].size();j++)
        {
            if(matrix[i][j]==0) continue;
            matrix[i][j]=1+min(matrix[i-1][j-1],min(matrix[i-1][j],matrix[i][j-1]));
            maxi=max(maxi,matrix[i][j]);
        }
    }
    return maxi;
}
int main()
{
    vector <vector <int>> matrix=  {  {0 , 1 , 1 , 0 , 1 , 0},
                                       {1 , 1 , 0 , 1 , 0 , 0},
                                       {0 , 1 , 1 , 1 , 0 , 0},
                                       {1 , 1 , 1 , 1 , 0 , 0},
                                       {1 , 1 , 1 , 1 , 1 , 0},
                                       {0 , 0 , 0 , 0 , 0 , 1},
                                       {0 , 1 , 0 , 1 , 0 , 1}
                                    };
    cout<<"Largest Square Matrix is = "<<count_largest_square_sub_matrix(matrix)<<"\n\n";
    return 0;
}
