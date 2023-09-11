#include <bits/stdc++.h>

using namespace std;

int a[55], b[55];

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}


int main(int argc, char const *argv[])
{
	srand(time(NULL));
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.ans", "w", stdout);

	int tc = 1000;
	while (tc--) {
		int n = 8;
		string s; s.clear();
		set <int> w; w.clear();
		for (int i = 1; i <= n; ++i) {
			int d = Rand(1, 3);
			w.insert(d);
			if (d == 1) s += 'a';
			else if (d == 2) s += 'b';
			else if (d == 3) s += 'c';
		}
		string t = s;
		int cnt = 0;
		sort(t.begin(), t.end());
		while (next_permutation(t.begin(), t.end())) {
			memset(a, 0, sizeof a);
			memset(b, 0, sizeof b);
			bool ok = true;
			for (int i = 0; i < n - 1; ++i) {
				a[s[i] - 'a']++;
				b[t[i] - 'a']++;
				bool tmp = true;
				for (int j = 0; j < 25; ++j) if (a[j] != b[j]) tmp = false;
				if (tmp) {
					ok = false;
				}
			}
			if (ok) cnt++;
		}
		if (cnt == 0 && w.size() == 3) cerr << s << endl;
	}

	return 0;
}