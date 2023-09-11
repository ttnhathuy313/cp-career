#include <bits/stdc++.h>

using namespace std;

const int N = 200;
int pre[N], res[N];

signed main() {
	int n;
	cin >> n;
	memset(pre, -1, sizeof pre);
	int root = -1;
	for (int i = 1; i <= n; ++i) {
		printf("? ");
		for (int j = 1; j < i; ++j) printf("1 ");
		printf("2 ");
		for (int j = i + 1; j <= n; ++j) {
			printf("1");
			if (j != n) printf(" ");
		}
		printf("\n");
		fflush(stdout);

		int ans;
		scanf("%d", &ans);
		if (ans == 0) {
			root = i;
			continue;
		}
		if (ans == i) continue;
		pre[ans] = i;
	}
	for (int i = 1; i <= n; ++i) if (pre[i] == -1) {
		printf("? ");
		for (int j = 1; j < i; ++j) printf("2 ");
		printf("1 ");
		for (int j = i + 1; j <= n; ++j) {
			printf("2");
			if (j != n) printf(" ");
		}
		printf("\n");
		fflush(stdout);

		int ans;
		scanf("%d", &ans);
		if (ans == 0) continue;
		pre[i] = ans;
	}
	int cur = root;
	for (int i = n; i >= 1; --i) {
		res[cur] = i;
		cur = pre[cur];
	}
	printf("! ");
	for (int i = 1; i <= n; ++i) {
		printf("%d", res[i]);
		if (i != n) printf(" ");
	}
	fflush(stdout);

	return 0;
}