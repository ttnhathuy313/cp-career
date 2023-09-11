#include<bits/stdc++.h>
using namespace std;
#define all(a) begin(a),end(a)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
const int mod=1e9+7;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int N=4005;
 
struct ordered_set {
	int sz = 0, bit[N];
 
	int size() {
		return sz;
	}
 
	void update(int k, int x) {
		k++;
		while (k < N) {
			bit[k] += x;
			k += k & -k;
		}
		sz += x;
	}
 
	int find_by_order(int k) {
		int ans = 0, sum = 0;
		for (int j = 17; j >= 0; --j) {
			ans += 1 << j;
			if (ans < N && sum + bit[ans] < k) {
				sum += bit[ans];
			} else {
				ans -= 1 << j;
			}
		}
		return ans + 1;
	}
 
	int order_of_key(int k) {
		k++;
		int ans = 0;
		while (k >= 1) {
			ans += bit[k];
			k -= k & -k;
		}
		return ans - 1;
	}
} st[N];
 
vector<int>adj,adj2;
int dp[2][N];
 
void solve(){
	int n;
	cin>>n;
	vector<int>a(2*n);
	string s;
	adj.resize(n+1);
	adj2.resize(n+1);
	for(int i=0;i<2*n;i++){
		char z;
		cin>>z;
		s+=z;
		cin>>a[i];
		if(z=='B'){
			adj[a[i]]=i;
		}
		else{
			adj2[a[i]]=i;
		}
	}
	for(int j=0;j<=n;j++){
		dp[0][j]=dp[1][j]=1e9;
		for(int i=0;i<2*n;i++){
			st[j].update(i, 1); 
		}
		for(int i=1;i<=j;i++){
			st[j].update(adj[i], -1);
		}
	}
	dp[0][0]=0;
	for(int i=0;i<2*n;i++){
		for(int j=0;j<=min(n,i);j++){
			int gt=st[j].order_of_key(adj[j+1]);
			dp[1][j+1]=min(dp[1][j+1],dp[0][j]+gt);
		}
		for(int j=0;j<=n;j++){
			if(i-j<0){
	continue;
			}
			if(i-j>n){
	continue;
			}
			int gt=st[j].order_of_key(adj2[i-j+1]);
			dp[1][j]=min(dp[1][j],dp[0][j]+gt);
		}
		for(int j=0;j<=n;j++){
			dp[0][j]=dp[1][j];
			dp[1][j]=1e9;
		}
		for(int j=0;j<=n;j++){
			if(i-j+1<=n&&i-j+1>0){
	st[j].update(adj2[i-j+1], -1);
			}
		}
	}
	cout<<dp[0][n];
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.ans", "w", stdout);
	int tc=1;
	//cin>>tc;
	for(int _=0;_<tc;_++){
		// cout<<"Case #"<<_+1<<": ";
		solve();
		if(_!=tc-1){
			cout<<'\n';
		}
	}
}