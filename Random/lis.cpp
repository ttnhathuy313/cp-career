#include <bits/stdc++.h>

using namespace std;

int a[8], length[8], k;

int solve(int k) {
	if (length[k] != -1) return length[k];
	int best = 1;
	for (int i = 1; i <= k; i++) {
		if (a[i] < a[k]) {
			best = max(best, solve(i) + 1);
		}
	}
	return length[k] = best;

}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("lis.INP", "r", stdin);
	freopen("lis.OUT", "w", stdout);

	for (int i = 1; i <= 8; i++) {
		cin >> a[i];
		length[i] = -1;
	}

	cin >> k;	
	cout << solve(k);

	return 0;
}