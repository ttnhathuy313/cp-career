#include<bits/stdc++.h>
using namespace std;typedef long long ll;
const int N=1e5+7;
vector<int>e[N];int L[N],R[N],E,n,i,m,fa[N][20],d[N],a[N],x,y,z,o,rt,op;ll s,b[N],c[N];
void ins(int u,int v){e[v].push_back(u);e[u].push_back(v);}
void ad(int x,ll z){for(int i=x;i<=n;i+=i&-i)b[i]+=z,c[i]+=z*(x-1);}
ll q(int x,ll v0=0,ll v1=0){
	for(int i=x;i;i-=i&-i)v0+=b[i],v1+=c[i];
	return x*v0-v1;
}
void add(int x,int y,ll z){ad(x,z);ad(y+1,-z);}
ll sum(int x,int y){return q(y)-q(x-1);}
void dfs(int x){
	for(int i=1;(1<<i)<=d[x];++i)fa[x][i]=fa[fa[x][i-1]][i-1];
	L[x]=R[x]=++E;add(L[x],L[x],a[x]);
	for(auto&y:e[x])if(y!=fa[x][0])fa[y][0]=x,d[y]=d[x]+1,dfs(y);R[x]=E; 
}
int go(int x,int t){for(i=19;i>=0;--i)if(t>>i&1)x=fa[x][i];return x;}
int lca(int x,int y){
	if(d[x]<d[y])swap(x,y);
	x=go(x,d[x]-d[y]);if(x==y)return x;
	for(i=19;i>=0;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main(){
		freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.ans", "w", stdout);
	for(scanf("%d%d",&n,&m),i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<n;++i)scanf("%d%d",&x,&y),ins(x,y);dfs(rt=1);
	for(;m--;){
		scanf("%d%d",&op,&x);
		if(op==1)rt=x;
		if(op==2){
			scanf("%d%d",&y,&z);
			o=lca(x,y)^lca(x,rt)^lca(y,rt);
			if(o==rt)add(1,n,z);
			else if(lca(o,rt)==o){
				x=go(rt,d[rt]-d[o]-1);
				add(1,L[x]-1,z);
				add(R[x]+1,n,z);
			}else add(L[o],R[o],z);
		}
		if(op==3){
			if(x==rt)s=sum(1,n);else
			if(lca(x,rt)==x)
				x=go(rt,d[rt]-d[x]-1),s=sum(1,L[x]-1)+sum(R[x]+1,n);
			else s=sum(L[x],R[x]);
			printf("%I64d\n",s);
		}
	}
}