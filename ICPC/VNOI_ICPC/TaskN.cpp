#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	
	int lim = (int)1e9, tot = 0;
	int ld = 1, rd = lim, ans = -1, len_a, len_b;
	while (ld <= rd) {
		int mid = (ld + rd) >> 1;
		printf("? 1 1 %I64d %I64d\n", mid, lim);
		fflush(stdout);
		int x;
		scanf("%I64d", &x);
		if (x > 0) {
			rd = mid - 1;
			ans = mid;
			len_b = x;
		} else ld = mid + 1;
	}
	int u = ans;
	int lr = 1, rr = lim;
	ans = -1;
	while (lr <= rr) {
		int mid = (lr + rr) >> 1;
		printf("? 1 1 %I64d %I64d\n", lim, mid);
		fflush(stdout);
		int x;
		scanf("%I64d", &x);
		if (x > 0) {
			rr = mid - 1;
			ans = mid;
			len_a = x;
		} else lr = mid + 1;
	}
	int l = ans;

	printf("! %I64d %I64d %I64d %I64d\n", u, l, u + len_a - 1, l + len_b - 1);
	fflush(stdout);

	return 0;
}