#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int oo = 1e16;
vector <int> digit(17, 0);
int p10[30], dem, S;

int num(vector <int> d) {
	int ret = 0;
	for (int i = dem; i >= 1; --i) ret = ret * 10 + d[i];
	return ret;
}
int sum(int a) {
	int ret = 0;
	while (a) {
		ret += a % 10;
		a /= 10;
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);


	p10[0] = 1;
	for (int i = 1; i <= 15; ++i) p10[i] = p10[i - 1] * 10;
	int k;
	cin >> k;
	cout << 1 << endl;
	int cur = 1;
	for (int turn = 2; turn <= k; ++turn) {
		int nxt = -1;
		digit = vector <int>(17, 0);
		int tmp = cur + 1; dem = S = 0;
		while (tmp) {
			S += tmp % 10;
			digit[++dem] = tmp % 10;
			tmp /= 10;
		}
		for (int i = 1; i <= dem; ++i) {
			for (int j = digit[i]; j < 10; ++j) {
				digit[i] = j;
				if (nxt == -1 || nxt * sum(num(digit)) > num(digit) * sum(nxt)) {
					nxt = num(digit);
				}
			}
		}
		
		cur = nxt;
		cout << cur << endl;
	}

	return 0;
}