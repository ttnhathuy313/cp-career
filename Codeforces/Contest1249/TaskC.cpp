#include <bits/stdc++.h>

using namespace std;
#define int long long

int Pow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

const int D = 40;
int Exp[D];

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.inp", "r", stdin);
	freopen("TaskC.out", "w", stdout);

	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector <int> d;
		d.clear();
		int p = 0;
		int lst = -1;
		memset(Exp, 0, sizeof Exp);
		//cerr << n << " : ";
		int _n = n;
		while(n) {
			Exp[p] = n % 3;
			//cerr << n % 3;
			if (n % 3 == 2) lst = p;
			n /= 3;
			p++;
		}
		//cerr << endl << lst << endl;

		if (lst == -1) {
			cout << _n << endl;
			continue;
		}
		for (int i = lst; i < D; ++i) {
			if (Exp[i] == 0) {
				Exp[i] = 1;
				for (int j = 0; j < i; ++j) Exp[j] = 0;
				break;
			}
		}
		int res = 0;
		for (int i = 0; i < D; ++i) {
			if (Exp[i] == 1) res += Pow(3, i);
		}
		cout << res << endl;
	}

	return 0;
}