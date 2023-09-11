#include <bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(),(x).end()
#define int long long
 
const int N = 510;
vector <int> pos[45];
int val[N][N], cnt[N];
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n, m, lim;
	cin >> n >> m >> lim;
	for (int i = 1; i <= n; i++) {
		string ch;
		cin >> ch;
		for (int j = 1; j <= m; j++) val[i][j] = ch[j - 1] - 'a';
	}
	int ans = 0;
	for (int i = 1; i < n; i++){
		for (int j = 1; j <= m; j++) cnt[j] = val[i][j] == 0 ? 1 : 0;
		for (int j = i + 1; j <= n; j++){
			for (int k = 0; k < 26; k++) pos[k].clear();
			int sum = 0;
			int l = 1;
			for (int k = 1; k <= m; k++){
				if (val[j][k] == 0) cnt[k]++;
				sum += cnt[k];
				while (sum > lim) sum -= cnt[l++];
				if (val[j][k] == val[i][k]) {
					if (pos[val[i][k]].empty() || pos[val[i][k]][pos[val[i][k]].size() - 1] < l) {
						pos[val[i][k]].push_back(k);
					}
					else {
						int ind = lower_bound(all(pos[val[i][k]]), l) - pos[val[i][k]].begin();
						ans += pos[val[i][k]].size() - ind;
						pos[val[i][k]].push_back(k);
					}
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}