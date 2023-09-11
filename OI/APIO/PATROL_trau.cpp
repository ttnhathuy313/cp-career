#include <bits/stdc++.h>
#define rep(a, b, c) for(int a(b); a <= (c); a++)
#define dec(a, b, c) for(int a(b); a >= (c); a--)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100005;

struct edge{ int u, v, w, next; } e[2 * MAX_N];

int front[MAX_N], decision[MAX_N][3];
int ecnt = 1, n, m, maxPath, maxPathLca, ans;

void addedge(int u, int v, int w){
    e[++ecnt] = (edge){u, v, w, front[u]};
    front[u] = ecnt;
}

int dfs(int u, int par){
    int branches[3] = {0, 0, 0};
    for(int now = front[u]; now != -1; now = e[now].next){
        int v = e[now].v;
        if(v == par)
            continue;
        int temp = dfs(v, u) + e[now].w;
        if(temp > branches[1]){
            branches[2] = branches[1];
            decision[u][2] = decision[u][1];
            branches[1] = temp;
            decision[u][1] = now;
        } else if(temp > branches[2]){
            decision[u][2] = now;
            branches[2] = temp;
        }
    }
    if(maxPath < branches[1] + branches[2]){
        maxPath = branches[1] + branches[2];
        maxPathLca = u;
    }
    return branches[1];
}

int main(){
   freopen("PATROL.INP", "r", stdin);
    freopen("PATROL.ANS", "w", stdout);

    memset(front, -1, sizeof(front));
    memset(decision, -1, sizeof(decision));

    scanf("%d%d", &n, &m);
    ans = 2 * (n - 1);
    rep(i, 1, n - 1){
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v, 1);
        addedge(v, u, 1);
    }

    dfs(1, 0);
    ans -= maxPath - 1;
    
    if(m == 2){
        maxPath = 0;
        
        int now = decision[maxPathLca][1];
        while(now != -1){
            e[now].w = e[now ^ 1].w = -1;
            now = decision[e[now].v][1];
        }
        now = decision[maxPathLca][2];
        while(now != -1){
            e[now].w = e[now ^ 1].w = -1;
            now = decision[e[now].v][1];
        }

        dfs(1, 0);
        ans -= maxPath - 1;
    }

    printf("%d\n", ans);

    return 0;
}