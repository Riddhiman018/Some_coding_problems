#include<bits/stdc++.h>
using namespace std;
#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x,y;
        ll sum = 0;
        char a[1000][1000];
        cin>>n>>m>>x>>y;
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        for(int i = 0; i<n;i++)
        {
            for(int j = 0; j<(m);j++)
            {
                if(a[i][j]=='*')sum+=0;
                else
                {
                    if(a[i][j+1]=='.')
                    {
                        sum+=MIN((2*x),y);
                        j = j+1;
                    }
                    else
                    {
                        sum+=x;
                    }
                }
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}