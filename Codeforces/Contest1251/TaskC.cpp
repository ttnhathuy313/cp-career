#include <bits/stdc++.h>

using namespace std;

bool cmp(char a, char b) {
	return ((a - '0') % 2 != (b - '0') % 2 && a < b);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.inp", "r", stdin);
	freopen("TaskC.out", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		sort(s.begin(), s.end(), cmp);
		cout << s << endl;
	}

	return 0;
}