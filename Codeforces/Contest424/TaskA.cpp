#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.inp", "r", stdin);
	freopen("TaskA.out", "w", stdout);

	int n;
	cin >> n;
	int cnt1 = 0;
	string s;
	cin >> s;
	for (int i = 0; i < n; ++i) if (s[i] == 'x') cnt1++;
	cout << min(abs(n / 2 - cnt1), abs(n - cnt1 - n / 2)) << endl;
	if (cnt1 < n / 2) {
		for (int i = 0; i < n; ++i) if (s[i] == 'X' && cnt1 != n / 2) {
			cnt1++;
			s[i] = 'x';
		}
		cout << s << endl;
	} else {
		for (int i = 0; i < n; ++i) if (s[i] == 'x' && cnt1 != n / 2) {
			cnt1--;
			s[i] = 'X';
		}
		cout << s << endl;
	}

	return 0;
}