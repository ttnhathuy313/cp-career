#include <bits/stdc++.h>
#define F first
#define S second
 
using namespace std;
 
pair< long long, pair<int,int> > mem[300005];
vector<int> v[3];
int n,m;
 
int main()
{
    freopen("TaskE.INP", "r", stdin);
    freopen("TaskE.ans", "w", stdout);
    cin >> n >> m;
    int i;
    for(i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x-1].push_back(y);
    }
    for(i=0;i<3;i++)
    {
        sort(v[i].begin(),v[i].end()); reverse(v[i].begin(),v[i].end());
    }
    for(i=0;i<=m;i++)
    {
        int a=mem[i].S.F,b=mem[i].S.S;
        if(a<v[0].size())
            mem[i+1]=max(mem[i+1],{v[0][a]+mem[i].F,{a+1,b}});
        if(b<v[1].size())
            mem[i+2]=max(mem[i+2],{v[1][b]+mem[i].F,{a,b+1}});
    }
    for(i=0;i<=m;i++)
        mem[i]=max(mem[i],mem[i-1]);
    long long cur=0,ans=0;
    for(i=0;i<=v[2].size();i++)
    {
        if(i*3>m)
            break;
        cerr << mem[m-i*3].F + cur << endl;
        ans=max(ans,mem[m-i*3].F+cur);
        if(i!=v[2].size())
            cur+=v[2][i];
    }
    cout << ans << endl;
}
