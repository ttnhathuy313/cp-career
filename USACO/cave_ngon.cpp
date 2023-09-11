#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;
char Map[1003][1003];
int bel[1003][1003], fa[500003], dp[500003], id, N, M;
int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }

int main() {
	freopen("cave.in", "r", stdin);
	freopen("cave.out", "w", stdout);
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; ++i) scanf("%s", Map[N - i + 1] + 1);
    for (int i = 2; i < N; ++i) {
        static bool vis[500003];
        vector<int> rt;
        for (int j = 2; j < M; ++j)
            if (Map[i][j] == '.') {
                int pj = j, pre = 0;
                while (Map[i][pj] == '.') {
                    if (Map[i - 1][pj] == '.') {
                        int f = find(bel[i - 1][pj]);
                        if (!pre)
                            pre = f;
                        else if (f != pre) {
                            dp[pre] = 1ll * dp[pre] * dp[f] % P;
                            fa[f] = pre;
                        }
                    }
                    ++pj;
                }
                if (!pre) {
                    dp[++id] = 1;
                    fa[id] = id;
                    pre = id;
                }
                rt.push_back(pre);
                while (j < pj) bel[i][j++] = pre;
            }
        for (auto t : rt)
            if (!vis[t]) {
                vis[t] = 1;
                ++dp[t];
            }
        for (auto t : rt) vis[t] = 0;
    }
    int tms = 1;
    for (int i = 1; i <= id; ++i)
        if (fa[i] == i)
            tms = 1ll * tms * dp[i] % P;
    cout << tms;
    return 0;
}