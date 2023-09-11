/*
	In this problem, I have to count how many subarrays in the input array that is 'exterminable'.
	This solution is based on the fact that: if we split an subarray into two parts then the whole subarray is 'exterminable' 
	if and only if the result of stack processing for each smaller subarray is the reversed version of another. Intead of 
	iterating through n ^ 2 subarrays, I take advantage of the structure of segment tree: Each node of the segment tree 
	will represent the interval [l, r] with mid = (l + r) / 2. Then, every subarrays with left endpoints <= mid and right 
	endpoints > mid will be proceeded in this node. By doing this, I will seperate every subarray in this node into 2 halfs:
	the first is [left_end_points, mid] and the second is [mid + 1, right_end_points]. According to the aforementioned
	observation, a subarray is satisfied iff the result of stack processing for each smaller subarray is the reversed version 
	of another. So, I only have to traverse through the right parts and count how many sufficient left parts in the node and add
	to the answer. In order to compare two set quickly, I used hashing in the same manner with string.

	As the sum of length of the entire segment tree is NlogN, the overall complexity of this solution is O(Nlogn*logn)
*/

#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define endl '\n'
typedef tuple <int, int, int> ti;
 
const int N = 3e5 + 5, MOD1 = 1e9 + 7, MOD2 = 1e9 + 207, base1 = 3e5 + 17, base2 = 3e5 + 19; // MOD and base are used for hashing
int basePow1[N], basePow2[N], res, a[N], n;
 
struct THash { // This is a struct of hash value, I used it as a value type
	int val1, val2, len = 0;
	THash() {val1 = val2 = len = 0;}
	void add(int x) { // Add a character to the end of the current string
		val1 = (val1 + basePow1[len] * x) % MOD1;
		val2 = (val2 + basePow2[len] * x) % MOD2;
		len++;
	}
	void pop(int x) { // Delete the character at the end of the current string
		len--;
		val1 = (val1 - basePow1[len] * x + MOD1 * MOD1) % MOD1;
		val2 = (val2 - basePow2[len] * x + MOD2 * MOD2) % MOD2;
	}
	bool operator < (THash other) const { // I added an operator so that it can works in std::map
		return (len < other.len && val1 < other.val1 && val2 < other.val2);
	}
};
 
void get(int l, int r) {
	if (l > r) return;
	int mid = (l + r) >> 1;
	map <ti, int> cnt;
	cnt.clear();
	stack <int> st; while (!st.empty()) st.pop();
	THash cur;
	for (int i = mid; i >= l; --i) { // Calculating the hash value for the left parts, by iterating from mid to l, 
		if (st.size() > 0 && st.top() == a[i]) { //the hash value is reversed itself so I don't have to reverse it later
			st.pop();
			cur.pop(a[i]); // Simulating the stack processing
		} else {
			st.push(a[i]);
			cur.add(a[i]);
		}
		ti mt = make_tuple(cur.val1, cur.val2, cur.len);
		cnt[mt]++; // Add the hash value to the map so that I can count later
	}
	cur = THash(); while (!st.empty()) st.pop(); int tmp = 0;
 
	for (int i = mid + 1; i <= r; ++i) { // Iterating over the right parts
		if (st.size() > 0 && st.top() == a[i]) {
			st.pop();
			cur.pop(a[i]);
		} else {
			st.push(a[i]);
			cur.add(a[i]);
		}
		ti mt = make_tuple(cur.val1, cur.val2, cur.len);
		tmp += cnt[mt]; // Count for how many left parts compatible with this right part.
	}
	res += tmp;
	if (l == r) return; // The base-case of the recursion
	get(l, mid); get(mid + 1, r); // calling for recursion
}
 
void solve() {
	res = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	get(1, n);
	cout << res << endl;
}
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	basePow1[0] = 1;
	for (int i = 1; i < N; ++i) basePow1[i] = basePow1[i - 1] * base1 % MOD1;
	basePow2[0] = 1;
	for (int i = 1; i < N; ++i) basePow2[i] = basePow2[i - 1] * base2 % MOD2;
	int q;
	cin >> q; // I have to solve q test cases
	while (q--) solve();
 
	return 0;
}