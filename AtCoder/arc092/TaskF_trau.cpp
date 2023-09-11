#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
 
#define pb push_back
#define mp make_pair
#define taskname "A"
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,int> ii;
typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
const int maxn = 1e3 + 5;
const int maxm = 2e5 + 5;
const int inf = 1e9;
const int mod = 1e9 + 7;
vector<int> adj[maxn];
int id[maxn][maxn];
bool vis[maxn][maxn];
bool vis1[maxn];
int a[maxm],b[maxm];
bool res[maxm];
int n , m;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TaskF.inp", "r", stdin);
    freopen("TaskF.ans", "w", stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= m ; ++i){
        cin >> a[i] >> b[i];
        adj[a[i]].pb(i);
    }
    for(int i = 1 ; i <= n ; ++i){
        queue<int> q;
        q.push(i);vis[i][i] = 1;
        while(q.size()){
            auto u = q.front();q.pop();
            for(auto &c : adj[u]){
                if(vis[i][b[c]] == 0){
                    vis[i][b[c]] = 1;q.push(b[c]);
                }
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        memset(vis1,0,sizeof vis1);
        vis1[i] = 1;
        for(auto &c : adj[i]){
            if(vis1[b[c]]){
                res[c] = 1;
                continue;
            }
            queue<int> q;q.push(b[c]);vis1[b[c]] = 1;
            while(q.size()){
                auto u = q.front();q.pop();
                for(auto &c : adj[u]){
                    if(vis1[b[c]] == 0){
                        vis1[b[c]] = 1;q.push(b[c]);
                    }
                }
            }
        }
        reverse(adj[i].begin(),adj[i].end());
        memset(vis1,0,sizeof vis1);
        vis1[i] = 1;
        for(auto &c : adj[i]){
            if(vis1[b[c]]){
                res[c] = 1;
                continue;
            }
            queue<int> q;q.push(b[c]);vis1[b[c]] = 1;
            while(q.size()){
                auto u = q.front();q.pop();
                for(auto &c : adj[u]){
                    if(vis1[b[c]] == 0){
                        vis1[b[c]] = 1;q.push(b[c]);
                    }
                }
            }
        }
    }
    for(int i = 1 ; i <= m ; ++i){
//        cout << vis[b[i]][a[i]] << " " << res[i] << " ";
        if(vis[b[i]][a[i]] == res[i])cout << "same\n";
        else cout << "diff\n";
    }
}