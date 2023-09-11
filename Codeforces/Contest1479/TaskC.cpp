#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 35;
int n, L, R;
vector <array<int, 3>> Edge;

void addEdge(int u, int v, int w) {
	Edge.push_back(array<int, 3>{u, v, w});
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	n = 32;
	cin >> L >> R;
	cout << "YES" << endl;
	if (L == R) {
		cout << "2 1" << endl;
		cout << "1 2 " << L;
		return 0;
	}
	R -= L;
	int k = (int)log2(R);
	addEdge(1, 2, L);
	addEdge(2, 3, 1);
	for (int i = 4; i <= 22; ++i) {
		addEdge(2, i, 1);
		for (int j = 3; j < i; ++j) {
			addEdge(j, i, (1 << (j - 3)));
		}
	}
	int suf = 0;
	for (int i = k; i >= 0; --i) if (R & (1 << i)) {
		addEdge(i + 3, 23, 1 + suf);
		suf += (1 << i);
	}
	addEdge(1, 23, L);
	cout << 23 << ' ' << Edge.size() << endl;
	for (auto d : Edge) {
		cout << d[0] << ' ' << d[1] << ' ' << d[2] << endl;
	}

	return 0;
}