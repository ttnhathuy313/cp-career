#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 5e5 + 5;
int n, a[N];
vector <ii> st;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("C11PAIRS.INP", "r", stdin);
	freopen("C11PAIRS.ANS", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int ok = 1;
			for (int k = i + 1; k <= j - 1; ++k) if (a[k] > min(a[i], a[j]))
				ok = 0;
			res += ok;
		}
	}
	cout << res << endl;

	return 0;
}