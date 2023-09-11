#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int s, v1, v2, t1, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int a = 2 * t1 + s * v1;
	int b = 2 * t2 + s * v2;
	if (a < b) {
		cout << "First";
	}
	if (a > b) cout << "Second";
	if (a==b) cout << "Friendship";

	return 0;
}