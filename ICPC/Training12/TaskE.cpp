#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, LG = 23, expand = 10;
int n, f[N * expand], ff[expand * N][LG], x, y;

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int jump(int start, int step) {
	start = f[start];
	step = step - 1;
	int res = start;
	for (int i = LG - 1; i >= 0; --i) if (step >= (1 << i)) {

		res = ff[res][i];
		step -= (1 << i);
	}
	return res;
}

int calc(string exp) {
	cerr << exp << endl;
	if (exp == "x") {
		return x;
	} else if (exp == "y") {
		return y;
	}
	string pref = "";
	int start = -1;
	for (int i = 0; i < exp.size(); ++i) {
		if (exp[i] == '(') {
			start = i;
			break;
		}
		pref += exp[i];
	}
	string operand1 = "", operand2 = "";
	int layer = 0;
	bool found = false;
	for (int i = start + 1; i < exp.size(); ++i) {
		if (exp[i] == '(') {
			layer++;
		} else if (exp[i] == ')') {
			layer--;
		}
		if (exp[i] == ',' && layer == 0) {
			operand1 = exp.substr(start + 1, i - start - 1);
			operand2 = exp.substr(i + 1, exp.size() - i - 2);
			found = true;
			break;
		}
	}

	if (found) {
		if (pref == "ff") {
			return jump(calc(operand1), calc(operand2));
		}
		if (pref == "fff") {
			return calc(operand1) + calc(operand2);
		}
	} else {
		string operand = exp.substr(start + 1, exp.size() - start - 2);
		return f[calc(operand)];
	}

	return 0;
}

int ff2(int x, int y) {
	int ans = f[x];
	for ( int i = 1; i < y ; i ++) {
		cerr << ans << endl;
		ans = 2* f[ans] ;
	}
	return ans ;
}

int calc2(string exp) {
	if (exp == "x") {
		return x;
	} else if (exp == "y") {
		return y;
	}
	string pref = "";
	int start = -1;
	for (int i = 0; i < exp.size(); ++i) {
		if (exp[i] == '(') {
			start = i;
			break;
		}
		pref += exp[i];
	}
	string operand1 = "", operand2 = "";
	int layer = 0;
	bool found = false;
	for (int i = start + 1; i < exp.size(); ++i) {
		if (exp[i] == '(') {
			layer++;
		} else if (exp[i] == ')') {
			layer--;
		}
		if (exp[i] == ',' && layer == 0) {
			operand1 = exp.substr(start + 1, i - start - 1);
			operand2 = exp.substr(i + 1, exp.size() - i - 2);
			found = true;
			break;
		}
	}

	if (found) {
		if (pref == "ff") {
			return ff2(calc(operand1), calc(operand2));
		}
		if (pref == "fff") {
			return calc(operand1) + calc(operand2);
		}
	} else {
		string operand = exp.substr(start + 1, exp.size() - start - 2);
		return f[calc(operand)];
	}

	return 0;
}


void solve() {
	string s1, s2, s3;
	getline(cin, s1);
	getline(cin, s2);
	getline(cin, s3);
	s3 = s3.substr(8, s3.size() - 9);
	x = stoi(s1.substr(8, s1.size() - 9));
	y = stoi(s2.substr(8, s2.size() - 9));

	cout << calc(s3) << endl;
	cout << calc2(s3) << endl;
}



signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	for (int i = 1; i < N * expand; ++i) {
		f[i] = phi(i);
	}
	for (int i = 1; i < N * expand; ++i) {
		for (int j = 0; j < LG; ++j) if (i + (1 << j) < N * expand) {
			if (j == 0) {
				ff[i][0] = 2 * f[i];
			} else {
				if (ff[i][j - 1] < N * expand)
					ff[i][j] = ff[ff[i][j - 1]][j - 1];
			}
		}
	}

	int tc;
	cin >> tc;
	string dummy;
	getline(cin, dummy);
	while (tc--) {
		solve();
	}

	return 0;
}