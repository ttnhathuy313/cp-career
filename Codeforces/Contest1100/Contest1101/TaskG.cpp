#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, LOGA = 31;
int a[N], basis[LOGA];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.inp", "r", stdin);
	freopen("TaskG.out", "w", stdout);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] ^= a[i - 1];
		int A = a[i];
		for (int j = 0; j < LOGA; ++j) {
			if ((A & (1 << j)) == 0) continue;
			if (!basis[j]) {
				basis[j] = A;
				res++;
				break;
			}
			A ^= basis[j];
		}
	}
	if (a[n]) cout << res << endl;
	else cout << -1 << endl;

	return 0;
}