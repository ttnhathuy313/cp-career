#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e6+5;
LL f[N][2],r1,r2,r3;int a[N];
int main(){
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.ANS", "w", stdout);
	int n,d;scanf("%d%d%d%d%d",&n,&r1,&r2,&r3,&d);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	memset(f,0x3f,sizeof(f)),f[1][0]=a[1]*r1+r3,f[1][1]=min(a[1]*r1+r1,1ll*r2);
	for(int i=2;i<=n;i++){
		f[i][0]=min(f[i-1][0]+d+a[i]*r1+r3,f[i-1][1]+d+min(a[i]*r1+r3+d+r1+d,min(a[i]*r1+r1,r2)+d+r1+d+r1));
		f[i][1]=min(f[i-1][0]+d+min(a[i]*r1+r1,r2),f[i-1][1]+d+min(a[i]*r1+r1,r2)+d+r1+d);
	}
	printf("%lld",min(f[n][0],f[n-1][1]+d*2+a[n]*r1+r3+r1));
	return 0;
}