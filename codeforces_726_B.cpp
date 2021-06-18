#include<bits/stdc++.h>
using namespace std;
#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	int t;
	cin>>t;
	while(t--)
	{
		int inp,x1,y1,x2,y2;
		vector<int> V;
		for(int i = 0; i<4;i++)
		{
			cin>>inp;
			V.push_back(inp);	
		}	
		//input is n,m,i,j
		//(x,y) means xth row, yth column
		if(abs(V[0]-V[2])>=abs(1-V[2]))
		{
			x1 = V[0];x2 = 1;
		}
		else{x2 = V[0];x1 = 1;}
		if(abs(V[1]-V[3])>=abs(1-V[3]))
		{
			y2 = V[1];y1=1;
		}
		else{y1 = V[1];y2=1;}
		cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
	}
	
	return 0;
}
