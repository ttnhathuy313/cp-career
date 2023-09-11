#include <bits/stdc++.h>

using namespace std;

struct D {
	int a, b, c, d;
};

struct Compare {
	bool operator () (const D &a, const D &b) {
		return a.a > b.a;
	}
};

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	priority_queue<D, vector <D>, Compare> d;
	d.push({1, 2, 3, 4});
	d.push({2, 3, 4, 5});
	cout << d.top().a << endl;

	return 0;
}