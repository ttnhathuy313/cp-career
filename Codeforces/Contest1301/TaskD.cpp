#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define int long long

	vector <pair <int, string>> res;


void print() {
	cout << res.size() << endl;
	for (auto v : res) cout << v.first << ' ' << v.second << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int n, m, k;
	cin >> n >> m >> k;
	if (k > 4 * n * m - 2 * n - 2 * m) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	res.clear();
	if (m == 1) {
		if (k <= n - 1) {
			res.push_back({k, "D"});
		} else {
			res.push_back({n - 1, "D"});
			res.push_back({k - n + 1, "U"});
		}
		print();
		return 0;
	}
	if (k <= 2 * (m - 1)) {
		if (k <= m - 1) {
			res.push_back({k, "R"});
		} else {
			res.push_back({m - 1, "R"});
			res.push_back({k - m + 1, "L"});
		}
		print();
		return 0;
	}
	res.push_back({m - 1, "R"}); res.push_back({m - 1, "L"});
	k -= 2 * (m - 1);
	int e = 2 * (m - 1) + (m - 1) * 2 + 1;
	int turn = min(k / e, n - 1);
	for (int i = 1; i <= turn; ++i) {
		res.push_back({1, "D"});
		res.push_back({m - 1, "RUD"});
		res.push_back({m - 1, "L"});
	}
	if (k > (n - 1) * e) {
		res.push_back({k - (n - 1) * e, "U"});
		print();
		return 0;
	}
	int rem = k - e * turn;
	if (rem == 0) {
		print();
		return 0;
	}
	rem--;
	res.push_back({1, "D"});
	if (rem <= m - 1) {
		
		if (rem > 0) res.push_back({rem, "R"});
		print();
		return 0;
	}
	res.push_back({m - 1, "R"});
	rem -= m - 1;
	int nxt = rem / 3;
	if (nxt > 0) res.push_back({nxt, "UDL"});
	rem %= 3;
	if (rem == 1) res.push_back({1, "L"});
	else if (rem == 2) res.push_back({1, "UD"});
	print();

	return 0;
}