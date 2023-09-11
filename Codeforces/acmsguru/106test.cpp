#include <bits/stdc++.h>

using namespace std;
#define int long long

const string NAME = "106";

int Rand(int l, int r) {
	return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
				(long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
				(long long)rand() * (RAND_MAX + 1) +
				(long long)rand()) % (r - l + 1);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(NULL));
	int tc = 300, i = 1;
	while (i <= tc) {
		ofstream inp((NAME + ".inp").c_str());
		int g = Rand(2, 19);
		int a = Rand(-5, 7) * g, b = Rand(-6, 4) * g, c = Rand(-12, 12) * g;
		inp << a << ' ' << b << ' ' << c << endl;
		int lx1 = Rand(-1234, 1234), rx1 = Rand(lx1, 1234);
		inp << lx1 << ' ' << rx1 << endl;
		lx1 = Rand(-1234, 1234), rx1 = Rand(lx1, 1234);
		inp << lx1 << ' ' << rx1 << endl;
		inp.close();

		system((NAME + ".exe").c_str());
		system((NAME + "_trau.exe").c_str());

		if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0) {
			cout << "WRONG ANSWER ON TEST : " << i << endl;
			break;
		}
		cout << "Test " << i << " : correct" << endl;
		i++;
	}	

	return 0;
}