#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, MOD = 1e9 + 7;
int t, k, f[N], g[N];

// gọi f[n] là số cách biểu diễn cho n bông hoa, lấy k bông trắng

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> t >> k;
	f[0] = 1;
	/*
	lấy số 4, k = 2
	RRRR
	RWWR
	RRWW
	WWRR
	....
	*/
	for (int i = 1; i <= (int)1e5; ++i) {
		f[i] = f[i - 1]; // lấy một bông hoa đen
		if (i - k >= 0) f[i] += f[i - k]; // lấy k bông hoa trắng
		f[i] = f[i] % MOD;
		if (i <= 4) cerr << "f[" << i << "] : " << f[i] << endl;
	}

	/* MẢNG CỘNG DỒN
	g[i] = tổng của f[j] với j <= i
	tổng của f giữa a và b = g[b] - g[a - 1]
	*/
	for (int i = 1; i <= (int)1e5; ++i) {
		g[i] = g[i - 1] + f[i];
		g[i] = g[i] % MOD;
	}

	while (t--) {
		int a, b;
		cin >> a >> b;
		// cần tính tổng của f[i] với i nằm giữa a và b f[a] + f[a + 1] + f[a + 2] + f[a + 3] + ... +  f[b]
		cout << (g[b] - g[a - 1] + MOD) % MOD << endl;
	}


	return 0;
}