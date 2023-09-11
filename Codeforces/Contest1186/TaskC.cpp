#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int n, pref[N], res;
string a, b;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> a >> b;
	int c = 0;
	for (int i = 0; i < b.size(); ++i) c += (b[i] == '1');
	for (int i = 0; i < a.size(); ++i) {
		pref[i] = (i == 0 ? 0 : pref[i - 1]) + (a[i] == '1');
	}
	int k = b.size();
	for (int i = k - 1; i < a.size(); ++i) {
		int d = pref[i] - (i == k - 1 ? 0 : pref[i - k]);
		if ((c + d) % 2 == 0) res++;
	}
	cout << res << endl;

	return 0;
}