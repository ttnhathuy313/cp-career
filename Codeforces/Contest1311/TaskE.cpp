#include <bits/stdc++.h>
 
using namespace std;
#define endl '\n'

const int N = 5005;
 
int f[N], dep[N], node[N];
int pre, maxd;
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);

	int T, n, d;
	cin >> T;
	while (T--)
	{
		pre = maxd = 0; memset(node, 0, sizeof node);
		cin >> n >> d;
		for (int i = 2; i <= n; ++i)
		{
			f[i] = i >> 1, dep[i] = dep[f[i]] + 1;
			if (node[dep[i]] == 0) node[dep[i]] = i, ++maxd;
			d -= dep[i];
		}
		if (d < 0) cout << "NO" << endl;
		else
		{
			for (int i = n; i >= 2; --i)
			{
				if (node[dep[i]] != i)
				{
					pre = maxd;
					while (dep[i] <= pre && d)
					{
						f[i] = node[dep[i]];
						dep[i] = dep[f[i]] + 1;
						if (dep[i] > maxd)
						{
							++maxd;
							node[maxd] = i;
						}
						--d;
					}
				}
			}
			if (d) cout << "NO" << endl;
			else
			{
				cout << "YES\n";
				for (int i = 2; i <= n; ++i) cout << f[i] << ' ';
				cout << endl;
			}
		}
	}
	return 0;
}