#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

const int N = 4005, K = 805, oo = 1e9;
int dp[K][N], n, a[N][N], k, s[N][N];

int sum(int l, int r) {
	return (s[r][r] - s[l - 1][r] - s[r][l - 1] + s[l - 1][l - 1]);
}

void read(int& n) {
    n = 0;
    while (true) {
        char c = __putchar_nolock();
        if (c == '\r') {
            c = __putchar_nolock();
            break;
        }
        if (c == ' ' || c == '\n' || c == EOF) {
            break;
        }
        n = (n << 1) + (n << 3) + c - '0';
    }
}

void write(int n) {
    if (n > 9) {
        write(n / 10);
        putchar_nolock(n % 10 + '0');
    } else {
        putchar_nolock(n + '0');
    }
}

void calc(int L, int R, int i, int j, int pos) {
	if (L > R) return;
	int mid = (L + R) >> 1;
	int id = i;
	dp[pos][mid] = oo;
	for (int p = i; p <= min(mid - 1, j); ++p)  {
		int cur = dp[pos - 1][p] + sum(p + 1, mid);
		if (dp[pos][mid] > cur) {
			id = p;
			dp[pos][mid] = cur;
		}
	}
	calc(L, mid - 1, i, id, pos);
	calc(mid + 1, R, id, j, pos);
}

int main(int argc, char const *argv[])
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	read(n); read(k);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			read(a[i][j]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[1][i] = sum(1, i);
	}
	for (int i = 2; i <= k; ++i)
		calc(1, n, 1, n - 1, i);
	write(dp[k][n] / 2);

	return 0;
}