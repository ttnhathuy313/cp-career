#include<bits/stdc++.h>
using namespace std;
long l,r,n,m,q,dm[200005],p[200005];
long a[200005],par[200005][20];
long last[200005],ans[200005];
int main(){
		freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.ans", "w", stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>dm[i];
		p[dm[i-1]]=dm[i];
		last[dm[i]]=m+1;
	}
	p[dm[n]]=dm[1];
	for(int j=0;j<=18;j++){
		for(int i=0;i<=m+1;i++){
			par[i][j]=m+1;
		}
	}
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=m;i>=1;i--){
		last[a[i]]=i;
		par[i][0]=last[p[a[i]]];
	}
	for(int j=1;(1<<j)<n;j++){
		for(int i=1;i<=m;i++){
			if(par[i][j-1]!=m+1){
			    par[i][j]=par[par[i][j-1]][j-1];
			}
		}
	}
	ans[m+1]=1e9;
	for(int i=m;i>=1;i--){
		long tmp=n-1,pos=i;
		for(int j=20;j>=0;j--){
			if(tmp-(1<<j)>=0){
				tmp=tmp-(1<<j);
				pos=par[pos][j];
			}
		}
		ans[i]=min(pos,ans[i+1]);
	}
	for(int i=1;i<=q;i++){
		scanf("%ld %ld",&l,&r);
		if(ans[l]<=r){
			printf("1");
		}else{
			printf("0");
		}
	}
}