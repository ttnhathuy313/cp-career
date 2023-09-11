#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 1e9 + 9, base1 = 5, base2 = 7;
int n, q, basePow1[N], basePow2[N];
string s;

struct Hash {
	int val1, val2;
	Hash() {
		val1 = val2 = 0;
	}
	Hash(int a, int b) : val1(a), val2(b) {}
	void append(int a) {
		val1 = (val1 * base1 % MOD1 + a + 1) % MOD1;
		val2 = (val2 * base2 % MOD2 + a + 1) % MOD2;
	}
} H[N][30];

bool operator == (const Hash a, const Hash b) {
	return (a.val1 == b.val1 && a.val2 == b.val2);
}

Hash getHash(int c, int l, int r) {
	int len = r - l + 1;
	return Hash((H[r][c].val1 - H[l - 1][c].val1 * basePow1[len] + MOD1 * MOD1) % MOD1,
				(H[r][c].val2 - H[l - 1][c].val2 * basePow2[len] + MOD2 * MOD2) % MOD2);
}

bool cmp(Hash a, Hash b) {
	if (a.val1 < b.val1) return true;
	else if (a.val2 < b.val2 && a.val1 == b.val1) return true;
	return false;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n >> q >> s;
	s = ' ' + s;
	basePow1[0] = basePow2[0] = 1;
	for (int i = 1; i <= n; ++i)
		basePow1[i] = basePow1[i - 1] * base1 % MOD1, basePow2[i] = basePow2[i - 1] * base2 % MOD2;
	for (int i = 0; i < 26; ++i) {
		Hash cur = Hash();
		for (int j = 1; j <= n; ++j) {
			if (s[j] - 'a' == i) cur.append(1);
			else cur.append(0);
			H[j][i] = cur;
		}
	}
	while (q--) {
		int x, y, len;
		cin >> x >> y >> len;
		vector <Hash> V1, V2; V1.clear(); V2.clear();
		for (int i = 0; i < 26; ++i) {
			V1.push_back(getHash(i, x, x + len - 1));
			V2.push_back(getHash(i, y, y + len - 1));
		}
		sort(V1.begin(), V1.end(), cmp);
		sort(V2.begin(), V2.end(), cmp);
		bool f = false;
		for (int i = 0; i < 26; ++i) if (!(V1[i] == V2[i])) {
			f = true;
			break;
		}
		if (f) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}