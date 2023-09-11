#include <bits/stdc++.h>

using namespace std;

const int N = 1006;
int n, a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int n;
	cin >> n;
	int start = -1;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
		if (a[i] != i && start == -1) {
			start = i;
		}
	}
	if (start == -1) {
		start = n + 1;
	}
	if ((n - start + 1) & 1) {
		cout << "TUAN" << endl;
	} else cout << "CPU" << endl;

	return 0;
}