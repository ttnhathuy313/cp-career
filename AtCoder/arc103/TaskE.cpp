#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair <int, int> ii;

const int N = 2e5 + 5;
string s;
int n, tot, id[N];
vector <ii> res;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> s;
	n = s.size();
	s = ' ' + s;
	if (s[1] != '1' || s[n] == '1') {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 1; i <= (n - 1) / 2; ++i) {
		if (s[i] != s[n - i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	int lst = 1; tot = 1; id[1] = 1;
	for (int i = 2; i <= n - 1; ++i) if (s[i] == '1') {
		id[i] = ++tot;
		res.push_back({tot, id[lst]});
		int rem = i - lst - 1;
		while (rem--) {
			res.push_back({++tot, id[i]});
		}
		lst = i;
	}
	res.push_back({id[n - 1], n});
	for (ii v : res) cout << v.first << ' ' << v.second << endl;

	return 0;
}