#include<bits/stdc++.h>

using namespace std;
#define endl '\n'

const int N = 3030;
int A[N], n, k, a, cnt2, cnt;
vector <int> ans[3030303];
queue <pair<int,int>> que;

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("TaskD.inp", "r", stdin);
	cin >> n >> k;
	string s; cin >> s; s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'R') A[i] = 1;
        if (!A[i] && A[i - 1]) {
            que.push({i - 1, 1});
        }
    }
    for (int i = 1; i <= k; i++) {
        if (que.empty()) break;
        cnt2 = i;
        while (!que.empty() && i == que.front().second) {
            cnt++;
            int j = que.front().first;
            que.pop();
            ans[i].push_back(j);
            A[j] = 0, A[j + 1] = 1;
            if (A[j - 1]) que.push({j - 1,i + 1});
            if (j + 2 <= n && !A[j + 2]) que.push({j + 1, i + 1});
        }
    }
    if (cnt < k || !que.empty()) {
    	cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= k; i++) {
        if (!ans[i].size()) break;
        while (ans[i].size() > 1 && cnt2 < k) {
            cnt2++;
            cout << "1 " << ans[i].back() << endl;
            ans[i].pop_back();
        }
        cout << ans[i].size() << ' ';
        for(auto j : ans[i]) cout << j << " ";
        cout << endl;
    }
}