#include <bits/stdc++.h>

using namespace std;

const string NAME = "C11PAIRS";

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc = 100;
	for (int t = 1; t <= tc; ++t) {
		ofstream inp((NAME + ".inp").c_str());
		int n = Rand(1200, 1500);
		inp << n << endl;
		for (int i = 1; i <= n; ++i) {
			inp << Rand(1, 2800) << " ";
		}
		inp << endl;
		inp.close();

		system((NAME + ".exe").c_str());
		system((NAME + "_trau.exe").c_str());

		if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0) {
			cout << "Test " << t << " : Wrong answer!" << endl;
			break;
		}
		cout << "Test " << t << " : Correct" << endl;
	} 

	return 0;
}