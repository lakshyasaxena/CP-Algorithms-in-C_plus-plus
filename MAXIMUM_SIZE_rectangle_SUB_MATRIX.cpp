#include <bits/stdc++.h>
using namespace std;
int get_area(pair<int,int>p1[] , int);
void mm(void);
int main()
{
    ios_base::sync_with_stdio(false);
    int t,i,j,ans;
    mm();
    int n,m,num;
    ans=0;
    cout<<"Enter the number of rows and columns\n";
    cin>>n>>m;
    pair <int,int> p1[m+1];
    for(i=1;i<=m;i++)
    {
        p1[i]=make_pair(i,0);
    }
    cout<<"Enter the elements of Matrix\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>num;
            if(num==0) { p1[j].second=0; }
            else
                p1[j].second+=num;
        }
        ans=max(get_area(p1,n),ans);
        /*for(j=1;j<=m;j++)
            cout<<p1[j].second<<" ";
        cout<<"\n"; */
    }
    cout<<"Largest rectangle has "<<ans<<" ones in it.\n";
    return 0;
}
int get_area(pair<int,int>p1[] , int n)
{
    int max_area=0,area;
    int i;
    /*for(i=1;i<=n;i++)
    {
        cout<<p1[i].first<<" "<<p1[i].second<<"\n";
    }
    cout<<"\n"; */

    stack <pair<int,int>> s1;
    pair <int,int> pp1;
    s1.push(p1[1]);
    for(i=2;i<=n;i++)
    {
        pp1=s1.top();
        if(p1[i].second>=pp1.second)
        {
            s1.push(p1[i]);
        }
        else
        {
            while(!s1.empty())
            {
                pp1=s1.top();
                if(p1[i].second>=pp1.second) {break;}
                s1.pop();
                if(s1.size()==0)
                {
                    area=pp1.second*(i-1);
                    max_area=max(max_area,area);
                    //cout<<"area ="<<area<<"\n";
                }
                else
                {
                    area=pp1.second*(i-s1.top().first-1);
                    max_area=max(area,max_area);
                    //cout<<"area ="<<area<<"\n";
                }
            }
            s1.push(p1[i]);
        }
    }
    //cout<<i<<"\n";

     while(!s1.empty())
        {
            pp1=s1.top();
            s1.pop();
             if(s1.size()==0)
                    {
                        area=pp1.second*(i-1);
                      //  cout<<"on empty stack area= "<<area<<"\n";
                        max_area=max(max_area,area);
                    }
                    else
                    {
                        area=pp1.second*(i-s1.top().first-1);
                      //  cout<<"area = "<<area<<"\n";
                        max_area=max(max_area,area);
                    }
        }


    //cout<<"max_area="<<max_area<<"\n";
    return max_area;
}
void mm(void)
{
    cout<<"Given a matrix of 0 and 1\n";
    cout<<"We have to determine the number of ones in largest rectangle of 1 in the matrix\n";
    cout<<"Example:\n";
    cout<<"1 1 0 1\n";
    cout<<"1 1 0 1\n";
    cout<<"1 0 0 1\n";
    cout<<"Largest rectangle formed with one has 4 ones\n\n";
}
