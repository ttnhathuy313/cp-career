#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 15;
ii a[N], b[N];
int n, m;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first >> a[i].second;
		if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i].first >> b[i].second;
		if (b[i].first > b[i].second) swap(b[i].first, b[i].second);
	}
	int t = 2;
	set <int> val; val.clear();
	while (t--) {
		for (int i = 1; i <= n; ++i) {
			bool flag1 = false, flag2 = false;
			for (int j = 1; j <= m; ++j) if (a[i] != b[j]) {
				if (a[i].first == b[j].second || a[i].first == b[j].first) flag1 = true;
				if (a[i].second == b[j].second || a[i].second == b[j].first) flag2 = true;
			}
			if (flag1 && flag2) {
				cout << -1 << endl;
				return 0;
			}
			if (flag1) val.insert(a[i].first);
			if (flag2) val.insert(a[i].second);
		}
		swap(n, m);
		swap(a, b);
	}
	if (val.size() == 1) cout << *(val.begin()) << endl;
	else if (val.size() > 1) cout << 0 << endl;
	else cout << -1 << endl;

	return 0;
}