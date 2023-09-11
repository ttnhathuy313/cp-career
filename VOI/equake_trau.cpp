#include <bits/stdc++.h>
#define int long long
#define maxn 3005
#define inf 2000000000000000000
#define mod 1000000007
#define pb push_back
#define mp make_pair
const double PI = acos(-1);
using namespace std;
typedef pair<int,int> pp;
int n,c,p[maxn],m; vector <pp> adj[maxn]; int vis[maxn],par[maxn];
int child[maxn],dp[maxn][maxn],ndp[maxn][maxn],sum[maxn];
int LO,HI,totalp=0;
void dfs (int x){
	vis[x]=true; int i,j,k,l,w; child[x]=0;
	for (i=0;i<adj[x].size();i++){
		j=adj[x][i].first; w = adj[x][i].second;
		if (!vis[j]){
			par[j]=x; dfs(j);
			/// something...
			for (l=0;l<=child[x]+child[j];l++) ndp[x][l]=inf;
			for (k=0;k<=child[j];k++){
				for (l=0;l<=child[x];l++){
					int val2 = abs(sum[j]-LO*child[j]-k);
					int val = val2/c; if (val2%c!=0) val++;
					val = val*w+dp[j][k]+dp[x][l];
					ndp[x][k+l]=min(ndp[x][k+l],val);
				}
			}
			for (l=0;l<=child[x]+child[j];l++) dp[x][l]=ndp[x][l];
			///
			child[x]+=child[j];
			sum[x]+=sum[j];
		}
	}
	/// something... not yet completed
	child[x]++; dp[x][child[x]]=inf;
	for (i=child[x]; i>0; i--) dp[x][i]=min(dp[x][i],dp[x][i-1]);
	sum[x]+=p[x];
}
main(){
	ios::sync_with_stdio(false); cin.tie(0); srand(time(NULL));
	//freopen("inp.txt","r",stdin); //freopen("out.txt","w",stdout);
	freopen("equake.inp","r",stdin); freopen("equake.ans","w",stdout);
	cin>>n>>c; int i,j,k,w,sump=0;
	for (i=1;i<=n;i++){
		cin>>p[i]; totalp+=p[i];
	}
	m = totalp%n; LO=totalp/n; HI = LO +1;
	for (i=1;i<n;i++){
		cin>>j>>k>>w;
		adj[j].pb({k,w}); adj[k].pb({j,w});
	}
	for (i=1;i<=n;i++){
		dp[i][0]=0; dp[i][1]=0;
		
	}
	dfs(1);
	cout<<dp[1][m];
	
		
}