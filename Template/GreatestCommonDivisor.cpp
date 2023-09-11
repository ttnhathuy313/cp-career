#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	return (a == 0) ? b : gcd(b % a, a);
}

int extended_gcd(int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	} else {
		int x1, x2;
		int d = extended_gcd(b % a, a, x1, x2);
		y = x1;
		x = -x1 * (b / a) + x2;
		return d;
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b;
	int g = extended_gcd(3, 4, a, b);
	cerr << g << ' ' << a << ' ' << b << endl;
	return 0;
}