#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, a[N], b[N], t[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int pos1, pos0 = -1;
	for (int i = 1; i <= n; ++i) {
		
		cin >> b[i];
		t[b[i]] = i + 1;
		if (b[i] == 1) pos1 = i;
		if (b[i] == 0) pos0 = i;
	}
	if (pos0 > pos1) {
		cout << n + pos1 << endl;
		return 0;
	}
	bool ok = true;
	for (int i = 2; i <= n; ++i)

	return 0;
}