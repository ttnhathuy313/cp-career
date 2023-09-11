#include<bits/stdc++.h>
using namespace std;
const int N=5100;
int dp[N][N][2],n,w,sz[N],a[N],b[N],x;
vector<int> g[N];
 
void dfs(int u){
	dp[u][1][1]=a[u]-b[u];sz[u]=1;
	dp[u][0][0]=0;dp[u][1][0]=a[u];
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		dfs(v);
		for(int j=sz[u];j>=0;j--){
			for(int k=sz[v];k>=0;k--){
				dp[u][j+k][0]=min(dp[u][j+k][0],dp[u][j][0]+dp[v][k][0]);
				dp[u][j+k][1]=min(dp[u][j+k][1],dp[u][j][1]+min(dp[v][k][0],dp[v][k][1]));;
			}
		}
		sz[u]+=sz[v];
	}
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.ans", "w", stdout);
	
	memset(dp,0x3f,sizeof(dp));
	cin>>n>>w;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(i!=1)cin>>x,g[x].push_back(i);
	}
	dfs(1);
	int ans=0;
	for(int i=n;i>=1;i--){
		if(dp[1][i][0]<=w||dp[1][i][1]<=w){
			ans=i;break;
		}
	}
	cout<<ans;
}