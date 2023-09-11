#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <time.h>
#include <set>
#include <deque>
 
using namespace std;
 
const int N = 3001;
const long long oo = 1e18 + 123;
 
typedef pair<int,int> pi;
typedef pair<pi,int> pii;
#define mp make_pair
#define getSz(x) ((x).size())
 
int n,m,c;
vector <pi> e[N];
long long p[N];
 
long long roundUp(long long x,long long y){
    return x % y == 0 ? x/y : x/y + 1;
}
 
namespace subtask2{
 
    bool isSub2(){
        for(int i = 1; i <= n; ++i) if((int)e[i].size() > 2) return 0;
        return 1;
    }
 
    int ver[N];
    long long f[N][N],dist[N],sum[N],avg;
    pi trace[N][N];
 
    void dfs0(int u,int p = 0,int i = 0){
        ver[++i] = u;
        for(pi ed : e[u]){
            int v = ed.first;
            if(v != p){
                dist[i] = ed.second;
                dfs0(v,u,i);
            }
        }
    }
 
    deque <pii> res;
 
    void traceback(int i,int j,long long cur = 0){
        if(i <= 1) return ;
        int ii = trace[i][j].first,jj = trace[i][j].second;
        cur += avg + j - jj;
        long long s = sum[n] - sum[i - 1];
        if(cur - s > 0){
            traceback(ii,jj,cur);
            res.push_back(mp(mp(ver[i - 1],ver[i]),cur - s));
        }else if(cur - s < 0){
            res.push_back(mp(mp(ver[i],ver[i - 1]),s - cur));
            traceback(ii,jj,cur);
        }else traceback(ii,jj,cur);
    }
 
    void run(){
        for(int i = 1; i <= n; ++i) if((int)e[i].size() == 1){
            dfs0(i);
            break;
        }
        /*cout << "Subtask 2 " << endl;
        for(int i = 1; i <= n; ++i){
            cout << ver[i] <<"/"<<dist[i] << "  ";
        }
        cout << "\n";*/
        // dp
        for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + p[ver[i]];
        avg = sum[n]/n;
        int k = sum[n] - avg * n;
        //cout << " ok " << avg << " & " << k << endl;
 
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j <= k; ++j) f[i][j] = oo;
        }
        
        for(int j = 0; j <= min(1,k); ++j){
            long long val = j ? avg + 1 : avg;
            f[1][j] = roundUp(llabs(val - p[ver[1]]),c) * dist[1];
        }
        
        for(int i = 2; i <= n; ++i){
            for(int j = 0; j <= min(i - 1,k); ++j) if(f[i - 1][j] < oo){
                for(int t = 0; t <= 1 && j + t <= k; ++t){
                    long long val = t ? avg + 1 : avg,rr = f[i - 1][j] + roundUp(llabs((avg + 1) * (j + t) + avg * (i - j - t) - sum[i]),c) * dist[i];
                    if(rr < f[i][j + t]){
                        f[i][j + t] = rr;
                        trace[i][j + t] = mp(i - 1,j);
                    }
                }
            }
        }
 
        cout << f[n][k] << endl;
 
        traceback(n,k);
 
        cout << res.size() << endl;
        while(res.size()){
            cout << res.front().first.first << " " << res.front().first.second << " " << res.front().second << endl;
            res.pop_front();
        }
    }
};
 
namespace subtaskFull{
 
    long long f[N][N],g[N],tmp[N],sum[N],avg;
    pi trace[N][N];
    int cnt[N],k;
    vector <int> dirchildren[N];
 
    void dfs(int u,int pa = 0){
        sum[u] = p[u];
        cnt[u] = 1;
        for(pi ed : e[u]){
            int v = ed.first;
            if(v != pa){
                dfs(v,u);
                sum[u] += sum[v];
                cnt[u] += cnt[v];
            }
        }
    }
 
    void dp(int u,int pa = 0,int dist = 0){
        for(int j = 0; j <= k; ++j){
            f[u][j] = oo;
            trace[u][j] = mp(-1,-1);
        }
        if(cnt[u] <= 1){
            // u is a leaf
            for(int j = 0; j <= min(1,k); ++j){
                f[u][j] = roundUp(llabs(avg + j - p[u]),c) * dist;
            }
        }else{
            bool cc = 0;
            int rmax = 0,prevChild = -1;
            for(pi ed : e[u]){
                int v = ed.first,d = ed.second;
                if(v == pa) continue;
                dp(v,u,d);
            }
            for(int j = 0; j <= k; ++j) g[j] = oo;
            for(pi ed : e[u]){
                int v = ed.first,d = ed.second;
                if(v == pa) continue;
                dirchildren[u].push_back(v);
                if(!cc){
                    cc = 1;
                    for(int j = 0; j <= min(cnt[v],k); ++j) if(f[v][j] < oo){
                        for(int t = 0; t <= 1 && t + j <= k; ++t){
                            if(g[j + t] > f[v][j]){
                                g[j + t] = f[v][j];
                                trace[v][j + t] = mp(0,j);
                            }
                            rmax = max(rmax,j + t);
                        }
                    }
                }else{
                    // the most unpleasant part
                    for(int j = 0; j <= k; ++j){
                        tmp[j] = g[j];
                        g[j] = oo;
                    }
                    int newRmax = rmax;
                    for(int j = rmax; j >= 0; --j){
                        for(int t = 0; t <= min(cnt[v],k) && t + j <= k; ++t){
                            if(tmp[j] + f[v][t] < g[j + t]){
                                g[j + t] = tmp[j] + f[v][t];
                                trace[v][j + t] = mp(prevChild,t);
                            }
                            newRmax = max(newRmax,t + j);
                        }
                    }
                    rmax = newRmax;
                }
                prevChild = v;
            }
            for(int j = 0; j <= min(cnt[u],k); ++j){
                if(g[j] < oo){
                    f[u][j] = g[j] + roundUp(llabs((avg + 1) * j + avg * (cnt[u] - j) - sum[u]),c) * dist;
                }
            }
        }
    }
    deque <pii> traceSave[N],res;
 
    void traceback(int u,int j){
        if(cnt[u] <= 1) return ;
        int v0 = dirchildren[u].back(),j0 = j;
        dirchildren[u].pop_back();
        while(true){
            int x = trace[v0][j0].second;
            j0 -= x;
            long long total = (avg + 1) * x + avg * (cnt[v0] - x);
            if(total > sum[v0]){
                traceSave[u].push_back(mp(mp(v0,x),total - sum[v0])); // v0 gets total - sum from u
            }else{
                traceSave[u].push_front(mp(mp(v0,x),total - sum[v0])); // u gets sum - total from v0
            }
            if(dirchildren[u].empty()) break;
            v0 = dirchildren[u].back();
            dirchildren[u].pop_back();
        }
        while(traceSave[u].size()){
            pii tmp = traceSave[u].front(); traceSave[u].pop_front();
            int v = tmp.first.first,j0 = tmp.first.second;
            long long cur = tmp.second;
            if(cur > 0){
                res.push_back(mp(mp(u,v),cur));
                traceback(v,j0);
            }else if(cur < 0){
                traceback(v,j0);
                res.push_back(mp(mp(v,u),-cur));
            }else{
                traceback(v,j0);
            }
        }
    }
    void run(){
        dfs(1);
        
        avg = sum[1]/n;
        k = sum[1] - avg * n;
 
        dp(1);
 
        cout << f[1][k] << endl;
 
        traceback(1,k);
 
        cout << res.size() << endl;
        while(res.size()){
            cout << res.front().first.first << " " << res.front().first.second << " " << res.front().second << endl;
            res.pop_front();
        }        
    }
};
 
void testcase(){
    cin >> n >> c;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i < n; ++i){
        int x,y,z;
        cin >> x >> y >> z;
        e[x].push_back(mp(y,z));
        e[y].push_back(mp(x,z));
    }
    if(n <= 1) cout << "0\n0";
    else if(subtask2::isSub2()) subtask2::run();
    else subtaskFull::run();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
 
    //freopen("a.inp","r",stdin); freopen("a.out","w",stdout);
    freopen("equake.inp","r",stdin); freopen("equake.ANS","w",stdout);
 
    // main program here
 
    int tcase = 1;
    //cin >> tcase;
 
    for(int i = 1; i <= tcase; ++i) testcase();
 
    // 
 
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    
    return 0;
}