#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int lab[N], Rank[N], n;

void init() {
	for (int i = 1; i <= n; ++i) lab[i] = -1;
}

int root(int x) {
	return (lab[x] == -1) ? x : lab[x] = root(lab[x]);
}

void Union(int u, int v) {
	int x = root(u), y = root(v);
	if (x == y) return;
	if (Rank[x] > Rank[y]) lab[y] = x;
	else {
		lab[x] = y;
		Rank[y] += (Rank[x] == Rank[y]);
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	return 0;
}