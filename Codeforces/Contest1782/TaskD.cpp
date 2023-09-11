#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int dist = 37;

	int mx = 0;
	for (int dist = 1; dist <= 300; ++dist) {
		int cnt = 0;
		for (int i = 1; i <= 10000; ++i) {
			for (int j = 1; j <= 10000; ++j) {
				if (i * i - j * j == dist) {
					cnt++;
				}
			}
		}
		mx = max(mx, cnt);
	}
	
	cout << mx << endl;

	return 0;
}