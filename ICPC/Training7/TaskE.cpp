#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, l[N], r[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n;
	int l_res = -(int)1e9 + 7, r_res = -1, id = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
		if (l[i] > r[i]) swap(l[i], r[i]);
		
		if (l[i] > l_res) {
			l_res = l[i];
			id = i;
		} else if (l[i] == l_res) {
			if (r[id] < r[i]) {
				id = i;
			}
		}
	}
	cerr << l_res << ' ' << r_res << endl;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (r[i] < l[id]) continue;
		res++;
	}
	cout << res << endl;

	return 0;
}