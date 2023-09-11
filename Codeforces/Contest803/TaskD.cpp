#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int k, n;
string s;

bool check(int mid) {
	int l = 1, r = 1;
	for (int turn = 1; turn <= k; ++turn) {
		int rem = mid;
		cerr << turn << ' ' << l << ' ' << r << endl;
		if (r != l) {
			if (r - l + 1 > rem) return false;
			rem -= r - l + 1;
			l = r;
			++l; ++r;
		}
		if (r == n + 1) return true;
		while (1) {
			while (s[r] != '-' && s[r] != ' ') {
				if (r == n) {
					break;
				}
				r++;
			}
			cerr << l << ' ' << r << endl;
			int len = r - l + 1;
			if (len > rem) break;
			else {
				l = r;
				rem -= len;
				if (r == n) return true;
				l++; r++;
			}
		}
	}
	if (r != n + 1) return false;
	return true;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> k; getline(cin, s);
	getline(cin, s);
	n = s.size(); s = ' ' + s;
	int l = 1, r = n, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	cout << ans << endl;

	return 0;
}