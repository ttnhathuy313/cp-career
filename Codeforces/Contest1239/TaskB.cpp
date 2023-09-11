#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 3e5 + 5;
int pref[N], n, cnt[N][4], realID[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n;
	string t;
	cin >> t;
	t = ' ' + t;
	int minVal = 0;
	for (int i = 1; i <= n; ++i) {
		if (t[i] == '(') pref[i] = pref[i - 1] + 1;
		else pref[i] = pref[i - 1] - 1;
		minVal = min(minVal, pref[i]);
	}
	if (pref[n] != 0) {
		cout << "0\n1 1\n";
		return 0;
	}
	string s; s.clear();
	s.push_back(' ');
	for (int i = 1; i <= n; ++i) if (pref[i] == minVal) {
		for (int j = i + 1; j <= n; ++j) {
			realID[(int)s.size()] = j;
			s.push_back(t[j]);
		}
		for (int j = 1; j <= i; ++j) {
			realID[(int)s.size()] = j;
			s.push_back(t[j]);
		}
		break;
	}
	if (s.size() == 1) s = t;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '(') pref[i] = pref[i - 1] + 1;
		else pref[i] = pref[i - 1] - 1;
		cnt[i][1] = cnt[i - 1][1] + (pref[i] == 1);
		cnt[i][2] = cnt[i - 1][2] + (pref[i] == 2);
		cnt[i][0] = cnt[i - 1][0] + (pref[i] == 0);
		minVal = min(minVal, pref[i]);
	}
	int last = 0, lastid = 0;
	int res = cnt[n][0];
	ii id(1, 1);
	for (int i = 1; i <= n; ++i) {
		if (pref[i] == 0) {
			if (last > res) {
				res = last;
				id = ii(lastid + 1, i);
			}
			lastid = i;
			last = 0;
		} else {
			if (pref[i] == 1) last++;
		}
	}
	last = 0, lastid = 0;
	for (int i = 1; i <= n; ++i) {
		if (pref[i] <= 1) {
			if (last + cnt[n][0] >= res && i != 1) {
				res = last + cnt[n][0];
				id = ii(lastid + 1, i);
			}
			lastid = i;
			last = 0;
		} else {
			if (pref[i] == 2) last++;
		}
	}

	cout << res << endl;
	cout << realID[id.first] << ' ' << realID[id.second] << endl;

	return 0;
}