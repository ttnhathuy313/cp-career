#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()

const int N = 2e5 + 5;
vector <int> a1, a2, a3;
bool ap[N];
int n;

int calc(int mid) {
	int tot = n - mid + 1;
	int id = lower_bound(a3.begin(), a3.end(), mid) - a3.begin();
	int ex = a3.size() - id;
	return tot - ex + id;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);

	int k1, k2, k3;
	cin >> k1 >> k2 >> k3;
	n = k1 + k2 + k3;
	for (int i = 1; i <= k1; ++i) {
		int d;
		cin >> d;
		a1.push_back(d);
		ap[d] = true;
	}
	for (int i = 1; i <= k2; ++i) {
		int d;
		cin >> d;
		a2.push_back(d);
	}
	for (int i = 1; i <= k3; ++i) {
		int d;
		cin >> d;
		a3.push_back(d);
	}
	sort(all(a1)); sort(all(a2)); sort(all(a3));
	int cur = 0, res = N;
	ap[0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (!ap[i]) cur++;
		int l = i + 1, r = n, ans = N;
		int mi = upper_bound(all(a3), i) - a3.begin();
		while (l <= r) {
			int mid = (l + r) >> 1;
			int cur = calc(mid);
			if (i == 1 && cur == 0) cerr << mid << endl;
			if (ans > cur) ans = cur;
			if (mid != n && calc(mid + 1) < cur) l = mid + 1;
			else if (mid != i + 1 && calc(mid - 1) < cur) r = mid - 1;
			else break;
		}
		ans = min(ans, k3);
		res = min(res, cur + ans - mi);
	}
	res = min(res, (int)(a1.size() + min((int)a3.size(), (int)a2.size())));
	cout << res << endl;

	return 0;
}