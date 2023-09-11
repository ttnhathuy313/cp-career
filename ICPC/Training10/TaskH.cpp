#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	set <int> a; a.clear();
	for (int i = 1; i <= n; ++i)
		a.insert(i);
	int res = 0;
	for (int i = 0; !a.empty(); ++i) {
		int m = a.size(), b = 0;
		set <int> tmp;
		tmp.clear();
		for (int j : a) {
			printf("? %d %d", j, i);
			fflush(stdout);
			int v;
			scanf("%d", &v);
			if (v == 1) {
				tmp.insert(j);
				b++;
			}
		}
		if (b < (m + 1) / 2) {
			res += (1 << i);
			a = tmp;
		} else {
			for (int v : tmp) {
				a.erase(v);
			}
		}
	}
	printf("! %d", res);
	fflush(stdout);
	

	return 0;
}