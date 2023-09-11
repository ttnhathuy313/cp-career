#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5e5 + 5;
int n, id[N], sz[N], temp[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int res = 0;
	cin >> n;
	memset(id, -1, sizeof id);
	for (int i = 1; i <= n; ++i) {
		cin >> sz[i];
		temp[i] = sz[i];
		vector <int> A(sz[i] + 5, 0);
		for (int j = 0; j < sz[i]; ++j) {
			cin >> A[j + 1];
		}
		for (int j = 1; j <= sz[i]; ++j) {
			if (id[A[j]] == -1) {
				continue;				
			}
			temp[id[A[j]]]--;
		}
		bool ok = true;
		for (int j = 1; j <= sz[i]; ++j) if (id[A[j]] != -1) {
			if (temp[id[A[j]]] != 0) ok = false;
		}
		for (int j = 1; j <= sz[i]; ++j) {
			temp[id[A[j]]] = sz[id[A[j]]];
		}
		if (ok == false) continue;
		for (int j = 1; j <= sz[i]; ++j) {
			id[A[j]] = i;
		}
		res++;
	}
	cout << res << endl;

	return 0;
}