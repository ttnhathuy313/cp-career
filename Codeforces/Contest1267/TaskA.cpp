#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
typedef pair <ii, int> iii;

struct event {
	int time, id;
	bool close;
	event() {}
	event(int _time, int _id, int _close) : time(_time), id(_id), close(_close) {}
	bool operator < (const event other) const {
		return (time < other.time || (time == other.time && close < other.close));
	}
};

const int N = 2e5 + 5;
int l[N], r[N], n, t[N];

main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.inp", "r", stdin);
	freopen("TaskA.out", "w", stdout);

	cin >> n;
	vector <event> D;
	D.clear();
	for (int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i] >> t[i];
		D.push_back(event(l[i], i, 0));
		D.push_back(event(r[i], i, 1));
	}
	sort(D.begin(), D.end());
	int res = 0;
	multiset <iii> T;
	T.clear();
	int curT = -1, start = 0, curID;
	for (int i = 0; i < D.size(); ++i) {
		int id = D[i].id;
		cerr << D[i].time << ' ' << id << ' ' << D[i].close << " " << start << ' ' << curT << endl;
		if (D[i].close == 0) {
			if (curT == -1) {
				start = D[i].time;
				curT = t[id];
				T.insert(iii(ii(curT, l[id]), id));
				curID = id;
				continue;
			}
			T.insert(iii(ii(t[id], l[id]), id));
			int encounter = (l[id] - start) / curT;
			if (start + (encounter + 1) * curT > l[id] + t[id] || start + (encounter + 1) * curT > r[curID]) {
				res += encounter;
				curT = t[id];
				start = l[id];
				curID = id;
			} else if (t[id] < curT) {
				start = start + (encounter + 1) * curT;
				res += encounter + 1;
				curT = t[id];
				curID = id;
			}
		} else    {
			T.erase(T.find(iii(ii(t[id], l[id]), id)));
			if (T.size() == 0) {
				res += (r[curID] - start) / curT;
				curT = -1;
			} else {
				if (T.find(iii(ii(t[curID], l[curID]), curID)) == T.end()) {
					res += (r[id] - start) / curT;
					iii v = *T.begin();
					ii tmp = v.first;
					start = start + ((r[id] - start) / curT) * curT;
					curT = tmp.first;
					curID = v.second;
				}
			}
		}
		cerr << res << endl;
	}
	cout << res << endl;

	return 0;
}