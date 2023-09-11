#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int n;
	string res;
	cout << "a" << endl;
	fflush(stdout);
	cin >> n;
	cout << "b" << endl;
	fflush(stdout);
	int x;
	cin >> x;
	n = max(n, x);
	res.resize(n);
	for (int i = 0; i < n; ++i) 
		res[i] = 'a';
	cout << res << endl;
	fflush(stdout);
	int cur, d;
	cin >> cur;
	for (int i = 0; i < n - 1; ++i) {
		res[i] = 'b';
		cout << res << endl;
		fflush(stdout);
		cin >> d;
		if (d < cur) {
			if (d == 0) break;
			res[i] = 'b';
			cur = d;
		} else res[i] = 'a';
	}
	if (cur == 1) res[n - 1] = 'b';
	cout << res << endl;
	fflush(stdout);

	return 0;
}