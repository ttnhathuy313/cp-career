#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

struct obj {
	int x, y, type1;
};

bool operator < (const obj a, const obj b) {
	if (a.type1 == b.type1) return a.x < b.x;
	else return a.type1 < b.type1;
}

const int N = 1e5 + 5;
int n, a[N];
vector <ii> res;
set <obj> avail1, avail;
stack <obj> spare;

void printNo() {
	cout << -1 << endl;
	exit(0);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int row = 0;
	for (int i = n; i >= 1; --i) {
		if (a[i] == 0) continue;
		if (a[i] == 1) {
			avail.insert({++row, i, 1});
			avail1.insert({row, i, 1});
		}
		if (a[i] == 2) {
			if (avail1.size() == 0) printNo();
			obj f1 = *(avail1.begin());
			int x = f1.x, y = f1.y;
			avail1.erase(f1);
			avail.erase(f1);
			avail.insert({x, i, 0});
			res.push_back({x, i});
			res.push_back({x, y});
		}
		if (a[i] == 3) {
			if (avail.size() == 0) printNo();
			obj f1 = *(avail.begin());
			int x = f1.x, y = f1.y;
			if (f1.type1 == 1) {
				avail1.erase(f1);
			}
			avail.erase(f1);
			avail.insert({++row, i, 0});
			res.push_back({row, i});
			res.push_back({row, y});
			if (f1.type1 == 1) res.push_back({x, y});
		}
	}
	for (obj rem : avail1) {
		res.push_back({rem.x, rem.y});
	}
	cout << res.size() << endl;
	for (ii d : res) 
		cout << n + 1 - d.first << ' ' << d.second << endl;

	return 0;
}