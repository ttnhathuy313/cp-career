#include <bits/stdc++.h>

using namespace std;
#define int long long 
typedef pair <int, int> ii;
typedef vector <int> BigInt;

const int BASE = (int)1e4;
int EXP[] = {1, 10, 100, 1000, 10000, 100000};

BigInt Cast(string &s) {
	BigInt ret;
	ret.clear();
	int i = s.size();
	while (i > 0) {
		int t = 0;
		for (int d = 0; d < 4; ++d) {
			if (--i < 0) break;
			t += (s[i] - '0') * EXP[d];
		}
		ret.push_back(t);
	}
	return ret;
}

BigInt operator+(const BigInt &a, const BigInt &b) {
	BigInt ret;
	ret.clear();
	int carry = 0;
	for (int i = 0; i < max(a.size(), b.size()); ++i) {
		if (i < a.size()) carry += a[i];
		if (i < b.size()) carry += b[i];
		ret.push_back(carry % BASE);
		carry = carry / BASE;
	}
	if (carry) ret.push_back(carry);
	return ret;
}

BigInt operator-(const BigInt &a, const BigInt &b) {
	int carry = 0;
	BigInt ret;
	ret.clear();
	for (int i = 0; i < a.size(); ++i) {
		int s = a[i] - carry;
		if (i < b.size()) s -= b[i];
		if (s < 0) carry = 1, s = (s + BASE);
		else carry = 0;
		ret.push_back(s);
	}
	while (ret.size() > 1 && ret.back() == 0) ret.pop_back();
	return ret;
}

BigInt operator*(const BigInt &a, const BigInt &b) {
	int n = a.size(), m = b.size();
	BigInt ret(n + m + 5, 0);
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			int k = (i + j);
			ret[k] += a[i] * b[j];
			ret[k + 1] += ret[k] / BASE;
			ret[k] %= BASE;
		}
	}
	while (ret.size() > 1 && ret.back() == 0)
		ret.pop_back();
	return ret;
}

void print(BigInt a) {
	int n = a.size();
	cout << a[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		int d;
		if (a[i] == 0) d = 1;
		else d = (int)log10(a[i]) + 1;
		for (int k = 0; k < 4 - d; ++k)
			cout << 0;
		cout << a[i];
	}
	cout << endl;
	return;
}

bool operator<(const BigInt &a, const BigInt &b) {
	if (a.size() != b.size()) {
		return (a.size() < b.size());
	} else {
		for (int i = a.size() - 1; i >= 0; --i) if (a[i] != b[i])
			return (a[i] < b[i]);
	}
	return false;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("BIGNUM.INP", "r", stdin);
	freopen("BIGNUM.OUT", "w", stdout);

	string s, t;
	cin >> s >> t;
	BigInt a = Cast(s), b = Cast(t);
	print(a + b);
	if (a < b) {
		cout << "-";
		print(b - a);
	} else print(a - b);
	print(a * b);

	return 0;
}