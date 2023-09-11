#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int res[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int n;
	string a, b;
	cin >> a >> b;
	n = a.size();
	bool ok = false;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) {
			ok = true;
			cnt++;
			cout << abs(a[i] - b[i]);
		} else {
			if (ok) cout << 0;
		}
	}
	if (cnt == 0) {
		cout << 0;
	}

	return 0;
}