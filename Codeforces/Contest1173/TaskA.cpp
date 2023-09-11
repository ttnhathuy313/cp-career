#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int x, y, z;
	cin >> x >> y >> z;
	char res1;
	if (x - y - z < 0) res1 = '-';
	else if (x - y - z > 0) res1 = '+';
	else res1 = '0';
	char res2;
	if (x - y + z < 0) res2 = '-';
	else if (x - y + z > 0) res2 = '+';
	else res2 = '0';
	if (res1 != res2) cout << "?";
	else cout << res1;

	return 0;
}