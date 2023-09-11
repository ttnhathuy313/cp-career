#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
const int mxn=1e5+5;
int n,m,a[mxn],c[mxn],ans[mxn];
inline int solve(int x){
	memset(c,0,sizeof(c));int rt=0,i=1,l=0,r=0;
	for(;i<=n;++i){
		++c[a[i]];
		if(c[a[i]]==1)++r;
		if(r>x){
			--i;
			for(int j=l;j<i+2;++j)--c[a[j]];
			r=0,l=i+1,++rt;
		}
	}
	return rt+1;
}
inline void bs(int l,int r){
	int sl=solve(l),sr=solve(r);
	if(sl==sr)for(int j=l;j<=r;++j)ans[j]=sl;
	else{
		int md=l+r>>1;
		bs(l,md),bs(md+1,r);
	}
}
int main(){
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.ans", "w", stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	int o=0;for(int i=1;i*i<=n*log2(n);++i)o=i,ans[i]=solve(i);
	bs(o+1,n);
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
}