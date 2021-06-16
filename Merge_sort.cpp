#include<bits/stdc++.h>
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
typedef long long ll;
ll inv_count = 0;
void merge(ll a[], ll l, ll m, ll r)
{
    ll b[100010], c[100010];
    ll size_1 = m-l+1;
    ll size_2 = r-m;
    ll p=0,q=0;
    for(ll i = l;i<=m;i++)
    {
        b[p] = a[i];
        p+=1;
    }
    for(ll j = m+1;j<=r;j++)
    {
        c[q] = a[j];
        q+=1;
    }
    p=0;q=0;ll final_index = l;
    while((p<size_1)&&(q<size_2))
    {
        if(b[p]>c[q])
        {
            a[final_index] = c[q];
            q+=1;
            final_index+=1;
            inv_count+=(size_1 - p);
        }
        else
        {
            a[final_index] = b[p];
            p+=1;
            final_index+=1;
        }
    }
    while(p<size_1)
    {
        a[final_index] = b[p];
        p+=1;
        final_index+=1;
    }
    while(q<size_2)
    {
        a[final_index] = c[q];
        q+=1;
        final_index+=1;
    }
}
void Mergesort(ll a[], ll l, ll r)
{
    if(l>=r)
    {
        return;
    }
    ll m = l + (r-l)/2;
    Mergesort(a, l, m);
    Mergesort(a, m+1, r);
    merge(a,l,m,r);
}
int main()
{
    ll a[100010];ll p = 0;
    ifstream fin;
    fin.open("count_inversions.txt");
    char c[100];
    while(!(fin.eof()))
    {
        fin.getline(c,7,'\n');
        string s(c);
        a[p] = stoll(s,nullptr,10);
        p+=1;
    }
    cout<<p<<"\n";
    fin.close();
    Mergesort(a,0,p-1);
    cout<<"\n"<<inv_count;
    return 0;
}
