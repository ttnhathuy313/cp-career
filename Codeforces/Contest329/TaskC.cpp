#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n, m;
set <ii> S;

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		S.insert(ii(u, v));
		S.insert(ii(v, u));
	}
	vector <int> A; A.clear();
	for (int i = 1; i <= n; ++i) A.push_back(i);
	int turn = 30000, d = 0;
	while (turn--) {
		random_shuffle(A.begin(), A.end());
		bool ok = true;
		for (int i = 0; i < n - 1; ++i) {
			if (S.find(ii(A[i], A[i + 1])) != S.end()) {
				ok = false;
				break;
			}
		}
		if (m == n && S.find(ii(A[n - 1], A[0])) != S.end()) ok = false;
		if (!ok) continue;
		for (int i = 0; i < n - 1; ++i) {
			cout << A[i] << ' ' << A[i + 1] << endl;
			m--;
			if (m == 0) break;
		}
		if (m == 1) cout << A[n - 1] << ' ' << A[0] << endl;
		return 0;
	}
	cout << -1 << endl;

	return 0;
}