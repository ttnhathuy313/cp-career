#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
typedef pair <int, int> ii;

const double EPS = 1e-9, pi = acos(-1);
const int N = 1e5 + 5; 
int r[N], h[N], n, F[N], dp[N];

bool cmp(ii a, ii b) {
	if (a.first == b.first) {
		return a.second < b.second;
	} else return a.first < b.first;
}

void add(int d, int id) {
	while (id <= n) {
		F[id] = max(F[id], d);
		id += (id & -id);
	}
}

int get(int i) {
	int res = 0;
	while (i) {
		res = max(res, F[i]);
		i -= (i & -i);
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> r[i] >> h[i];
	vector <ii> A; A.clear();
	for (int i = 1; i <= n; ++i) {
		A.push_back({r[i] * r[i] * h[i], i});
	}
	sort(A.begin(), A.end(), cmp);
	int res = 0, id = 0, prev = A[0].first;
	for (int i = 0; i < n; ++i) {
		if (prev != A[i].first) {
			while (id < i) {
				add(dp[id], A[id].second);
				id++;
			}
		}
		dp[i] = get(A[i].second) + A[i].first;
		res = max(res, dp[i]);
		prev = A[i].first;
	}
	cout << fixed << setprecision(9) << pi * res << endl;

	return 0;
}