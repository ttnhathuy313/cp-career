#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

int freq[30], dp[30][30], n, okay[30];
string s;

void solve() {
	memset(freq, 0, sizeof freq);
	cin >> n >> s;
	int res = n + 1, toBound = -1;
	for (int bound = 1; bound <= 26; ++bound) if (n % bound == 0) {
		for (int i = 0; i < n; ++i) {
			freq[s[i] - 'a' + 1]++;
		}
		int target = n / bound;
		int cur_res = 0;
		vector <ii> V; 
		V.clear();
		for (int i = 1; i <= 26; ++i) {
			V.push_back({max(0, target - freq[i]), i});
		}
		sort(V.begin(), V.end());

		for (int i = 0; i <	bound; ++i) {
			cur_res += V[i].first;
		}
		for (int i = 1; i <= 26; ++i) {
			freq[i] = 0;
		}
		if (cur_res < res) {
			memset(okay, 0, sizeof okay);
			for (int i = 0; i < min((int)V.size(), bound); ++i) {
				auto v = V[i];
				okay[v.second - 1] = 1;
			}
			toBound = bound;
		}
		res = min(res, cur_res);
	}
	cout << res << endl;
	memset(freq, 0, sizeof freq);
	int target = n / toBound;
	string t = s;
	int rem = 0;
	for (int i = 0; i < n; ++i) if (okay[t[i] - 'a']) {
		freq[t[i] - 'a']++;
		if (freq[t[i] - 'a'] > target) {
			t[i] = '?';
			rem++;
		}
	} else t[i] = '?';
	memset(freq, 0, sizeof freq);
	for (int i = 0; i < n; ++i) {
		if (t[i] != '?') {
			freq[t[i] - 'a']++;
		}
	}
	queue <int> q;
	while (!q.empty()) q.pop();
	for (int i = 0; i < 26; ++i) if (freq[i]) {
		if (freq[i] < target) {
			int v = target - freq[i];
			while (v--) {
				q.push(i);
				rem--;
			}
		}
	}
	for (int i = 0; i < 26; ++i) if (freq[i] == 0) {
		if (rem > 0) {
			int v = target;
			while (v--) {
				q.push(i);
			}
		}
	}
	for (int i = 0; i < n; ++i) if (t[i] == '?') {
		t[i] = char('a' + q.front());
		q.pop();
	}
	cout << t << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}