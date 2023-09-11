#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	if (1LL * k * (k - 1) < n) {
		cout << "NO" << endl;
		return 0;
	} else cout << "YES" << endl;
	int cnt = 0;
	for (int i = 1; i <= k; ++i) {
		int pt1 = i, pt2 = 1;
		while (pt2 <= k) {
			if (cnt == n) break;
			cout << pt2 << ' ' << pt1 + 1 << endl;
			pt1 = (pt1 + 1) % k;
			pt2++;
			cnt++;
		}
		if (cnt == n) break;
	}

	return 0;
}