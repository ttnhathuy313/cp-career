#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("ZALMOXIS.INP", "r", stdin);
	freopen("ZALMOXIS.OUT", "w", stdout);
	int n, k; cin >> n >> k;
	int rem = n + k, x;
	stack <int> s, cur;
	stack <ii> ans;
	for(int i = 0; i < n; i++){
		cin >> x;
		s.push(x);
	}
	cur.push(30);
	while (!s.empty()){
		if (cur.top() <= s.top()){
			ans.push(ii(cur.top(), cur.top() == s.top()));
			if (s.top() == cur.top()) s.pop();
			cur.pop();
		} else{
			int x = cur.top();
			cur.pop();
			cur.push(x - 1);
			cur.push(x - 1);
		}
	}
	while (!cur.empty()) {
		ans.push(ii(cur.top(),0));
		cur.pop();
	}
	vector <int> fans;
	while (rem > 0){
		if (ans.size() == rem || ans.top().second == 1 || ans.top().first==0){
			fans.push_back(ans.top().first);
			ans.pop();
			rem--;
		} else{
			x = ans.top().first;
			ans.pop();
			ans.push(ii(x - 1,0));
			ans.push(ii(x - 1,0));
		}
	}
	for(int i = 0; i < n + k; i++){
		cout << fans[i] << " ";
	}
	return 0;
}