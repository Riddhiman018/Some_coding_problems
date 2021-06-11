#include<bits/stdc++.h>
using namespace std;
int main()
{
    string A;
    cin>>A;
    if(A.find("0000000")+1||A.find("1111111")+1)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}