#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int N = 5005;
int n, t[N], d[N], pref_min[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskM.INP", "r", stdin);
	freopen("TaskM.OUT", "w", stdout);

	int n;
	cin >> n;
	vector <ii> V; V.clear();
	for (int i = 1; i <= n; ++i) {
		cin >> t[i] >> d[i];
		V.push_back({d[i], i});
	}
	sort(V.begin(), V.end());
	int cur = 0;
	vector <int> res; res.clear();
	for (ii v : V) {
		int i = v.second;
		res.push_back(i);
		if (cur + t[i] > d[i]) {
			cout << "*" << endl;
			return 0;
		}
		cur += t[i];
	}

	int savedTime = 0;
	for (int i = 0; i < n; ++i) {
		int val = res[i], id = i, minGap = (int)1e15;
		int time = savedTime;
		for (int j = i; j < n; ++j) {
			int cur = res[j];
			if (j > i && minGap >= t[cur]) {
				if (cur < val) {
					val = cur;
					id = j;
				}
			}
			minGap = min(minGap, d[cur] - t[cur] - time);
			time += t[cur];
		}
		res.erase(res.begin() + id);
		res.insert(res.begin() + i, val);
		savedTime += t[val];
	}
	for (int i : res) {
		cout << i << ' ';
	}
	cout << endl;


	return 0;
}