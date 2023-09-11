#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, LOG = 65;
int b[N], cnt[LOG];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int n;
	cin >> n;
	int d = 0, id = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		int lb = (int)log2(b[i] & -b[i]);
		cnt[lb]++;
		if (cnt[lb] > d) {
			d = cnt[lb];
			id = lb;
		}
	}
	cout << n - d << endl;
	for (int i = 1; i <= n; ++i) {
		int lb = (int)log2(b[i] & -b[i]);
		if (lb != id) cout << b[i] << endl;
	}

	return 0;
}