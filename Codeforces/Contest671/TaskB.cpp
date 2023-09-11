#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5e5 + 5;
int n, k, a[N];

bool check(int mid) {
	int s = 0, cnt = 0;
	for (int i = 1; i <= n; ++i) {
		s += max(0LL, mid - a[i]);
		if (a[i] <= mid) cnt++;
	}
	int have = 0;
	for (int i = 1; i <= n; ++i)
		have += max(0LL, a[i] - mid);
	if (cnt == 0) return 1;
	return (s <= k && have >= s && cnt);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int l = 1, r = (int)1e9, lw = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1, lw = mid;
		else r = mid - 1;
	}
	// cerr << lw << endl;
	int rem = 0;
	for (int i = 1; i <= n; ++i)
		rem += max(0LL, lw - a[i]);
	vector <int> A; A.clear();
	for (int i = 1; i <= n; ++i) if (a[i] >= lw)
		A.push_back(a[i] - lw);
	int bf = rem;
	sort(A.begin(), A.end(), greater <int>());
	if (A[0] == 0) {
		cout << 0 << endl;
		return 0;
	}
	int pre = -1, up = -1;
	A.push_back(0);
	multiset <int> S; S.clear();
	for (int i = 0; i < A.size(); ++i) {
		int v = A[i];
		if (v != pre) {
			if (i != 0) {
				int slice = (pre - A[i]);
				if (slice * i < rem) {
					rem -= slice * i;
				} else {
					int down = rem / i;
					up = pre - down;
					for (int k = 0; k < (rem % i); ++k)
						S.insert(up - 1);
					for (int k = (rem % i); k < i; ++k)
						S.insert(up);
					for (int k = i; k < A.size() - 1; ++k)
						S.insert(A[k]);
					break;
				}
			}
			pre = A[i];
		}
	}
	k -= bf;
	int ff = 0;
	for (int v : S) ff += v;
	for (int i = 1; i <= n; ++i) if (a[i] < lw)
		S.insert(0);
	k = min(k, ff);
	while (k--) {
		int fi = *(S.begin()), lst = *(S.rbegin());
		S.erase(S.find(fi)); S.insert(fi + 1);
		S.erase(S.find(lst)); S.insert(lst - 1);
	}
	cout << *(S.rbegin()) - *(S.begin()) << endl;

	return 0;
}