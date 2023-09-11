#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int sgn[N], p10[N], ans[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	string s;
	p10[0] = 1;
	for (int i = 1; i <= 100; ++i) p10[i] = p10[i - 1] * 10;
	int n = 0, pre = 1, neg = 0, pos = 0, num = 0;
	while (cin >> s) {
		if (s == "?") {
			++n;
			sgn[n] = pre;
			string t;
			cin >> t;
			if (t == "+") pre = 1;
			else pre = -1;
			if (sgn[n] == 1) pos++;
			else neg++;
		} else {
			for (int i = s.size() - 1; i >= 0; --i) {
				num += p10[s.size() - 1 - i] * (s[i] - '0');
			}
			break;
		}
	}
	int lw = pos - neg * num;
	if (lw > num) {
		cout << "Impossible\n";
		return 0;
	}
	int up = pos * num - neg;
	if (up < num) {
		cout << "Impossible\n";
		return 0;
	}
	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (sgn[i] == -1) {
			ans[i] = -1;
			cur--;
		} else {
			ans[i] = num;
			cur += num;
		}
	}
	if (cur > num) {
		int reduce = cur - num;
		for (int i = 1; i <= n; ++i) if (sgn[i] == 1) {
			int r = ans[i];
			ans[i] -= min(ans[i] - 1, reduce);
			reduce -= r - ans[i];
			cur -= r - ans[i];
			if (reduce == 0) break;
		}
	}
	if (cur > num) {
		int reduce = cur - num;
		for (int i = 1; i <= n; ++i) if (sgn[i] == -1) {
			int r = ans[i];
			ans[i] -= min(reduce, num - 1);
			reduce -= min(reduce, num - 1);
			cur -= min(reduce, num - 1);
			if (reduce == 0) break;
		}
	}
	cout << "Possible\n";
	int f = 0;
	for (int i = 1; i <= n; ++i) {
		cout << abs(ans[i]) << ' ';
		f += ans[i];
		if (i != n) {
			if (sgn[i + 1] == 1) cout << "+ ";
			else cout << "- ";
		} else cout << "= " << num;
	}

	return 0;
}