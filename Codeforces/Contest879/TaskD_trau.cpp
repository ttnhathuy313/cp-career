#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int maxn=1e5+5;
 
int n,k,m;
int a[maxn],S[maxn],cnt[maxn],top; 
 
int main()
{	
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.ANS", "w", stdout);
	cin>>n>>k>>m;
	bool one_color=true;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++) if(a[i]!=a[i-1]){ one_color=false; break; } 
	
	if(one_color){
		cout<<(ll)n*m%k<<endl;
		return 0;
	}
	//消除内部的块 
	for(int i=1;i<=n;i++){
		S[++top]=a[i];
		if(top>1&&S[top]==S[top-1]) cnt[top]=cnt[top-1]+1;
		else cnt[top]=1;
		if(cnt[top]>=k) top=top-k;
	}
 
	int L=1,R=top;
	
	ll t=0;
	while(S[L]==S[R]&&L<R){
		int l=L,r=R,cnt=0;
		while(S[l]==S[L]&&l<r&&cnt<k){ cnt++; l++; } 
		while(S[r]==S[L]&&l<r&&cnt<k){ cnt++; r--; }
		if(cnt==k){ L=l; R=r; t+=k; }
		else break; 
	} 
	
	one_color=true;
	for(int i=L;i<R;i++) if(S[i]!=S[i+1]){ one_color=false; break; }
	if(one_color){
		ll mid=(ll)(R-L+1)*m%k;
		if(mid) cout<<mid+t<<endl;
		else cout<<0<<endl; 
	}
	else cout<<(ll)(R-L+1)*m+t<<endl;
}