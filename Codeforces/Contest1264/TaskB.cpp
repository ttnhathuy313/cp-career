#include <bits/stdc++.h>

using namespace std;

int A[5], a[5], d[5];

void solve1() {
	for (int i = 1; i <= 4; ++i) a[i] = A[i];
	for (int i = 1; i <= 3; ++i) {
		int s = 0;
		for (int j = i + 1; j <= 4; ++j) s += a[j];
		if (a[i] != 0) a[i]--;
		else if (s != 0) return;
		while (a[i] > 0) {
			a[i + 1]--;
			a[i]--;
		}
	}
	if (a[4] != 0) a[4]--;
	bool ok = true;
	for (int i = 1; i <= 4; ++i) if (a[i] != 0) ok = false;
	if (!ok) return;
	cout << "YES" << endl;
	for (int i = 1; i <= 4; ++i) a[i] = A[i];
	for (int i = 1; i <= 3; ++i) {
		if (a[i] != 0) {
			cout << d[i] << ' ';
			a[i]--;
		}
		while (a[i] > 0) {
			cout << d[i + 1] << ' ';
			a[i + 1]--;
			a[i]--;
			cout << d[i] << ' ';
		}
	}
	if (a[4] == 1) cout << d[4] << ' ';
	exit(0);
}

void solve2() {
	for (int i = 1; i <= 4; ++i) {
		a[i] = A[i];
	}
	if (a[2] == 0) return;
	a[2]--;
	if (a[1] > a[2]) return;
	a[2] -= a[1]; a[1] = 0;
	for (int i = 2; i <= 3; ++i) {
		if (i != 2) {
			if (a[i] != 0) a[i]--;
			else if (a[4] != 0) return;
		}
		while (a[i] > 0) {
			a[i + 1]--;
			a[i]--;
		}
	}	
	if (a[4] == 1) a[4]--;
	bool ok = true;
	for (int i = 1; i <= 4; ++i) if (a[i] != 0) ok = false;
	if (!ok) return;
	cout << "YES" << endl;
	for (int i = 1; i <= 4; ++i) {
		a[i] = A[i];
	}
	if (a[2] == 0) return;
	a[2]--;
	cout << d[2] << ' ';
	if (a[1] > a[2]) return;
	for (int i = 1; i <= a[1]; ++i) {
		cout << d[1] << ' ' << d[2] << ' ';
	}
	a[2] -= a[1]; a[1] = 0;
	for (int i = 2; i <= 3; ++i) {
		if (i != 2) {
			if (a[i] != 0) {
				a[i]--;
				cout << d[i] << ' ';
			} else if (a[4] != 0) return;
		}
		while (a[i] > 0) {
			cout << d[i + 1] << ' ' << d[i] << ' ';
			a[i + 1]--;
			a[i]--;
		}
	}	
	if (a[4] == 1) {
		cout << d[4];
		a[4]--;
	}
	exit(0);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	d[1] = 0, d[2] = 1, d[3] = 2, d[4] = 3;
	cin >> A[1] >> A[2] >> A[3] >> A[4];
	solve1();
	solve2();
	reverse(A + 1, A + 5);
	d[1] = 3, d[2] = 2, d[3] = 1, d[4] = 0;
	solve1();
	solve2();
	cout << "NO" << endl;

	return 0;
}