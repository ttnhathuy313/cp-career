#include <bits/stdc++.h>

using namespace std;

int bi(string s) {
	reverse(s.begin(), s.end());
	int res = 0;
	for (int i = 0; i < s.size(); ++i) if (s[i] == '1')
		res += (1 << i);
	return res;
}

string show(int d) {
	string ret; ret.clear();
	while (d) {
		ret = char((d % 2) + '0') + ret;
		d /= 2;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int i = 0;
	for (i = 1; i <= 4; ++i) cerr << "lmao" << endl;
	return 0;
}