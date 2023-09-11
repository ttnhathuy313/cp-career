#include <bits/stdc++.h>

using namespace std;

const int maxN = 17, oo = 1e9;
int tsp[maxN][(1 << maxN)], cost[maxN][maxN], n, start;

int TSP(int i, int mask) {
	if (mask == (1 << n) - 1) return cost[i][start];
	if (tsp[i][mask] != -1) return tsp[i][mask];
	else {
		int tmp = oo;
		for (int j = 1; j <= n; ++j) if (j != i && (mask & (1 << (j - 1)) == 0)) {
			tmp = min(tmp, cost[i][j] + TSP(j, mask | (1 << (j - 1))));
		}	
		return tsp[i][mask] = tmp;
	}
}

void input() {
	memset(tsp, -1, sizeof tsp);
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) 
			cost[i][j] = oo;
	while (m--) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		cost[u][v] = cost[v][u] = c;
	}
	scanf("%d", &start);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TSP.inp", "r", stdin);
	freopen("TSP.out", "w", stdout);

	input();
	printf("%d\n", TSP(start, 0));

	return 0;
}
