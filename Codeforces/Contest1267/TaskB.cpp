#include <bits/stdc++.h>

using namespace std;

const int N = 3e6 + 5;
int sz[N];
char c[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.inp", "r", stdin);
	freopen("TaskB.out", "w", stdout);

	string s;
	cin >> s;
	set <char> C;
	C.clear();
	for (int i = 0; i < s.size(); ++i) {
		C.insert(s[i]);
	}
	char pre = '/';
	int cnt = 0, block = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != pre) {
			sz[block] = cnt;
			cnt = 0;
			c[block] = pre;
			block++;
		}
		cnt++;
		pre = s[i];
	}
	if (block % 2 == 0) {
		cout << 0 << endl;
		return 0;
	}
	sz[block] = cnt;
	c[block] = pre;
	int mid = block / 2 + 1;
	bool ok = true;
	if (sz[mid] < 2) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= block / 2; ++i) {
		if (c[i] != c[block - i + 1]) ok = false;
		if (sz[i] + sz[block - i + 1] <= 2) ok = false;
	}
	if (ok == false) cout << 0 << endl;
	else cout << sz[mid] + 1 << endl;

	return 0;
}