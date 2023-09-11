#include <bits/stdc++.h>

using namespace std;
#define all(a)           a.begin(),a.end()
#define pb push_back
#define pii pair <int, int>
#define mx 100005

pii ara[mx];
int arr[mx];
vector<int>tree[3*mx];


void init(int n, int b, int e)
{
    if(b==e)
    {
        tree[n].pb(ara[b].second);
        return;
    }
    int l=n*2,r=l+1,mid=(b+e)/2
    init(l,b,mid);
    init(r,mid+1,e);
    merge(all(tree[l]),all(tree[r]),back_inserter(tree[n]));
}

int query(int n, int b, int e, int i, int j, int k)
{
    if(b==e)
    {
        return tree[n].back();
    }
    int l=n*2,r=l+1,mid=(b+e)/2;
    int x = upper_bound(all(tree[l]),j)-lower_bound(all(tree[l]),i);
    if(x>=k) {
        return query(l,b,mid,i,j,k);
    }
    else
        return query(r,mid+1,e,i,j,k-x);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i=1;i<=n;i++)
    {
        cin >> ara[i].first;
        ara[i].second=i;
        arr[i]=ara[i].first;
    }

    sort(ara+1,ara+n+1);

    init(1,1,n);

    while(m--)
    {
        int a,b;
        cin >> a >> b;
        int c = (b - a + 2) / 2;
        int ans=query(1,1,n,a,b,c);
        ans=arr[ans];
        cout << ans << endl;
    }
    return 0;
}