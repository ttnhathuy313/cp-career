#include <bits/stdc++.h>

using namespace std;

int a[4444];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("BinarySearch.INP", "r", stdin);
	freopen("BinarySearch.OUT", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> a[i];
	int q;
	cin >> q;
	while (q--) {
		int A;
		cin >> A;
		int l = 1, r = n, ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			cerr << l << ' ' << r << ' ' << mid << endl;
			if (a[mid] > A) r = mid - 1;
			else {
				ans = mid;
				l = mid + 1;
			}
		}
		cerr << ans << endl;
		cerr << l << " " << r << endl;
		if (a[ans] == A) {
			cout << "Co so can tim" << endl;
		} else cout << "Khong co!" << endl;
	}

	return 0;
}