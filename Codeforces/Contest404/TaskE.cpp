#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 1e6 + 5, offset = 1e6;
int p[N], n, cnt[N * 4], res, f[N * 4];
string s;

void solve() {
	p[0] = 0;
	int mx = -1;
	memset(cnt, 0, sizeof cnt);
	cnt[offset]++;
	for (int i = 1; i <= n; ++i) {
		p[i] = p[i - 1] + (s[i] == 'L' ? -1 : 1);
		mx = max(mx, p[i]);
		cnt[p[i] + offset]++;
	}
	if (mx < 0) return;
	if (cnt[p[n] + offset] == 1) {
		cout << 1 << endl;
		exit(0);
	}
	vector <int> st;
	st.clear();
	for (int i = n; i >= 1; --i) {
		while (st.size() && p[st.back()] <= p[i])
			st.pop_back();
		st.push_back(i);
	}
	memset(f, 0, sizeof f);
	reverse(st.begin(), st.end());
	int add_up = 0, mn = N * 5;
	for (int k = st.size() - 1; k >= 0; --k) {
		int i = st[k], j = (k == st.size() - 1 ? n : st[k + 1] - 1);
		if (p[i] <= 0) break;
		if (k != st.size() - 1) add_up += p[st[k + 1]] - p[st[k]];
		for (int v = j; v >= i; --v) {
			// cerr << v << ' ' << p[v] + add_up << " " << add_up << endl;
			f[p[v] + add_up + offset]++;
			cnt[p[v] + offset]--;
			mn = min(mn, p[v] + add_up);
		}
		if (f[p[n] + offset] + (p[n] - add_up - 1 + offset >= 0 ? cnt[p[n] - add_up - 1 + offset] : 0) == 1) res++;
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> s;
	n = s.size();
	s = ' ' + s;
	solve();
	for (int i = 1; i <= n; ++i) {
		s[i] = (s[i] == 'L' ? 'R' : 'L');
	}
	solve();
	cout << res << endl;

	return 0;
}