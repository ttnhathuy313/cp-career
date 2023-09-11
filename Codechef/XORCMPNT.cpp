#include <bits/stdc++.h>

using namespace std;

const int K = 31, N = 1e5 + 5;
int basis[K], a[N];

void solve() {
	int k, m;
	cin >> k >> m;
	memset(basis, 0, sizeof basis);
	memset(a, 0, sizeof a);
	for (int i = 1; i <= m; ++i) {
		cin >> a[i];
		int A = a[i];
		for (int j = 0; j < k; ++j) {
			if ((A & (1 << j)) == 0) continue;
			if (!basis[j]) {
				basis[j] = A;
				break;
			}
			A ^= basis[j];
		}
	}
	int d = 0;
	for (int i = 0; i < k; ++i) if (basis[i]) d++;
	cout << (1 << (k - d)) << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("XORCMPNT.INP", "r", stdin);
	freopen("XORCMPNT.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}