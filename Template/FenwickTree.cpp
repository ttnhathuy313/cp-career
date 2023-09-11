#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 1e5 + 5, oo = 1e9;
int tree[N], freq[N], a[N], n;

//This works for sum queries

// int read(int id) { //  This reads the cumulative frequency
// 	int sum = 0;
// 	while (id) sum += tree[id], id -= (id & -id);
// 	return sum;
// }

// void update(int id, int val) { //This updates the frequency of elements
// 	while (id <= maxID) tree[id] += val, id += (id & -id);
// }

//This works for maximum queries
void init_ft() {
	for (int i = 1; i <= n; ++i) tree[i] = -oo;
}

void update(int id, int val) {
	while (id <= n) tree[id] = max(tree[id], val), id += (id & -id);
}

int read(int id) {
	int ret = -oo;
	while (id) ret = max(ret, tree[id]), id -= (id & -id);
	return ret;
}

void scale(int c) { //Scaling tree
	for (int i = 1; i <= n; ++i) tree[i] /= c;
}

int bin_find(int CFre) { // Find the index where read(idx) == CFre
	int bit_mask = 1LL << (int(log2(n)) + 1); //YOU HAVE TO FIND THIS BEFORE
	int id = 0;
	while (bit_mask) {
		int next_id = id + bit_mask;
		bit_mask = bit_mask >> 1;
		if (next_id > n) continue;
		if (CFre == tree[next_id]) return next_id;
		else if (CFre > tree[next_id]) {
			CFre -= tree[next_id];
			id = next_id;
		}
	}
	if (CFre) return -1; else return id;
}

int bin_find_max(int CFre) { // This return the maximal one
	int bit_mask = 1LL << (int(log2(n)) + 1);
	int id = 0;
	while (bit_mask) {
		int next_id = id + bit_mask;
		bit_mask = bit_mask >> 1;
		if (next_id > n) continue;
		if (CFre >= tree[next_id]) {
			id = next_id;
			CFre -= tree[id];
		}
	}
	if (CFre) return -1; else return id;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("FenwickTree.inp", "r", stdin);
	freopen("FenwickTree.out", "w", stdout);
	cin >> n;
	init_ft();
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		update(i, a[i]);
		cout << "Maximal element from 1 to " << i << " is " << read(i) << endl;
	}
	//for (int i = 1; i <= n; ++i) cout << "Maximal element from 1 to " << i << " is " << read(i) << endl;

	return 0;
}
