#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> P;
typedef pair<int,P> P1;
 
#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mp1(a,b,c) P1(a,P(b,c))
 
int RET=0;
 
vector<P1> f(const vector<P> &vec,int W,int H){
	//sort(vec.begin(),vec.end());
	vector<P1> ret;
	set<int> S;
	S.insert(0);
	S.insert(H);
	for(P p: vec){
		auto itr=S.lower_bound(p.sc);
		int x=*itr; int y=*--itr;
		ret.push_back(mp1(y,x,p.fr));
		S.insert(p.sc);
	}
	auto itr=S.begin();
	while(1){
		int x=*itr;
		itr++;
		if(itr==S.end())break;
		int y=*itr;
		ret.push_back(mp1(x,y,W));
	}
	sort(ret.begin(),ret.end());
	return ret;
}
 
int solve(int W,int H,int N,vector<P> p){
	if(RET>=2*(W+H))return 0;
	if(N==0)return 2*(W+H);
	vector<P> L,R;
	int m;
	if(1){
		/*vector<int> X;
		for(int i=0;i<N;i++){
			X.push_back(p[i].fr);
		}
		sort(X.begin(),X.end());
		X.erase(unique(X.begin(),X.end()),X.end());*/
		if(p[0].fr==p[N-1].fr){
			int ret=0;
			vector<int> Y;
			Y.push_back(0);
			Y.push_back(H);
			for(int i=0;i<N;i++){
				Y.push_back(p[i].sc);
			}
			sort(Y.begin(),Y.end());
			for(int i=0;i+1<Y.size();i++){
				chmax(ret,Y[i+1]-Y[i]);
			}
			chmax(RET,max(2*(H+max(W-p[0].fr,p[0].fr)),2*(ret+W)));
			return max(2*(H+max(W-p[0].fr,p[0].fr)),2*(ret+W));
		}
		//m=X[(X.size()-1)/2];
		//m=p[(p.size()-1)/2].fr;
		m=W/2;
		for(int i=0;i<N;i++){
			if(p[i].fr<=m){
				p[i].fr=m-p[i].fr;
				L.push_back(p[i]);
			}
			else {
				p[i].fr-=m+1;
				R.push_back(p[i]);
			}
		}
	}
	reverse(L.begin(),L.end());
	int ret=0;
	vector<P1> vec[2]={f(L,m,H),f(R,W-m-1,H)};
	map<int,int> M[2];
	int k[2]={};
	while(k[0]<vec[0].size()||k[1]<vec[1].size()){
		int t;
		if(k[0]==vec[0].size())t=1;
		else if(k[1]==vec[1].size())t=0;
		else if(vec[0][k[0]].fr<=vec[1][k[1]].fr)t=0;
		else t=1;
		P1 pp=vec[t][k[t]]; k[t]++;
		auto itr=M[1-t].lower_bound(pp.sc.fr);
		if(itr!=M[1-t].end()){
			chmax(ret,2*((pp.sc.fr-pp.fr)+itr->sc+pp.sc.sc)+2);
		}
		if(itr!=M[1-t].begin()){
			--itr;
			chmax(ret,2*((itr->fr-pp.fr)+itr->sc+pp.sc.sc)+2);
		}
		itr=M[t].lower_bound(pp.sc.fr);
		while(itr!=M[t].end()&&itr->fr+itr->sc<=pp.sc.fr+pp.sc.sc)M[t].erase(itr++);
		bool ok=itr==M[t].begin();
		if(!ok){
			--itr;
			ok=itr->fr+itr->sc<pp.sc.fr+pp.sc.sc;
		}
		if(ok)M[t].insert(pp.sc);
	}
	chmax(RET,ret);
	//chmax(ret,solve(m,H,L.size(),L));
	//chmax(ret,solve(W-m-1,H,R.size(),R));
	return ret;
}
 
int main(){
	freopen("TaskF.inp", "r", stdin);
	freopen("TaskF.ans", "w", stdout);
	int w,h,n;
	vector<P> vec;
	scanf("%d%d%d",&w,&h,&n);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		vec.push_back(P(a,b));
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i+1<vec.size();i++){
		chmax(RET,2*(h+vec[i+1].fr-vec[i].fr));
	}
	solve(w,h,n,vec);
	for(int i=0;i<n;i++){
		swap(vec[i].fr,vec[i].sc);
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i+1<vec.size();i++){
		chmax(RET,2*(w+vec[i+1].fr-vec[i].fr));
	}
	solve(h,w,n,vec);
	cout<<RET<<endl;
	return 0;
	/*w=h=100000000;
	n=10000;
	for(int i=0;i<n;i++){
		int a=rand()%(w+1);
		int b=rand()%(w+1);
		vec.push_back(P(a,b));
	}*/
	sort(vec.begin(),vec.end());
	cout<<solve(w,h,n,vec)<<endl;
}