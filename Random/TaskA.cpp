#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
int n, m, a[N];

bool check(int k) {
	int tmp = a[1] + k >= m ? 0 : a[1];
	for (int i = 2; i <= n; i++) {
		if (tmp < a[i]) {
			if (!(m - a[i] + tmp <= k)) tmp = a[i];
		}
		if (tmp > a[i]) {
			if (a[i] + k < tmp) return 0;
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int l = 0, r = m, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid) == 0) {
			l = mid + 1;
		}else {
			ans = mid;
			r = mid - 1;
		}
		cerr << "a1 " << a[1] << endl ;
		cerr << l << " " << r << " " << mid << endl;
	}

	cout << ans << endl;
	

	return 0;
}