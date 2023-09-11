#include <bits/stdc++.h>

using namespace std;

int cnt[105];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		set <int> dis;
		dis.clear();
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			cnt[x] ++;
			dis.insert(x);
		}
		int minSize = 105;
		for (int v : dis) {
			minSize = min(minSize, cnt[v]);
		}
		if (dis.size() == 2) {
			cout << n - minSize + 1 << endl;
		} else cout << n << endl;
	}

	return 0;
}