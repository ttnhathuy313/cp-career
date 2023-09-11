#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, k, a, m, x[N];

bool check(int mid) {
	int distance = x[1] / (a + 1) + (n - x[mid] + 1) / (a + 1);
	for (int i = 2; i <= mid; i++) {
		distance += (x[i] - x[i - 1]) / (a + 1);  
	}
	cerr << distance <<endl;
	return distance >= k;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> k >> a >> m;
	for (int i  = 1; i <= m; i++) {
		cin >> x[i];
	}

	check(4);
	// int l = 1, r = m, ans = -1 ;
	// while (l <= r) {
	// 	int mid = (l + r) / 2;
	// 	if (check(mid) == 1) {
	// 		ans = mid;
	// 		l = mid + 1;
	// 	} else {
	// 		r = mid - 1;
	// 	}
	// 	cerr << l << ' '  << r << " " << mid << endl; 
	// }
	// cout << ans << endl;


	return 0;
}