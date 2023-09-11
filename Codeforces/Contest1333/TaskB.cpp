#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N], b[N];
multiset <int> S;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		S.clear();
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			S.insert(a[i]);
		}
		for (int i = 1; i <= n; ++i)
			cin >> b[i];
		bool ok = true;
		for (int i = n; i >= 1; --i) {
			S.erase(S.find(a[i]));
			int need;
			if (b[i] > a[i]) need = 1;
			else if (b[i] < a[i]) need = -1;
			else need = 0;
			if (need == 0) continue;
			if (S.find(need) == S.end()) {
				ok = false;
				break;
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}