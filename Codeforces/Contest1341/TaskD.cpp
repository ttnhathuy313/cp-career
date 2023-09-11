#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 2005;
int n, k, dp[N][N];
vector <ii> D[N]; // cost, num
string S[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string s[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		for (int j = 0; j < 10; ++j) {
			int cost = 0;
			for (int k = 0; k < 7; ++k) {
				if (S[j][k] == '0') {
					if (s[i][k] == '1') {
						cost = -1;
						break;
					}
				} else {
					if (s[i][k] == '0') cost++;
				}
			}
			if (~cost) {
				// cerr << i << ' ' << j << ' ' << cost << endl;
				D[i].push_back({cost, j});
			}
		}
	}
	dp[n + 1][0] = 1;
	for (int i = n; i >= 1; --i) {
		for (int j = k; j >= 0; --j) {
			for (ii v : D[i]) if (v.first <= j) {
				dp[i][j] |= dp[i + 1][j - v.first];
			}
		}
	}
	if (!dp[1][k]) {
		cout << -1 << endl;
		return 0;
	}
	int rem = k;
	for (int i = 1; i <= n; ++i) {
		ii id(0, 0);
		for (ii v : D[i]) if (rem >= v.first) {
			if (dp[i + 1][rem - v.first]) {
				// cerr << "~~ " << i << ' ' << v.second << ' ' << v.first << endl;
				id = max(id, {v.second, v.first});
			}
		}
		cout << id.first;
		rem -= id.second;
	}

	return 0;
}