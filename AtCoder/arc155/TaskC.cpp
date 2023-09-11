#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, a[N], b[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	int n_odd = 0;
	bool found_pairs = false;
	bool found_b = false;
	for (int i = 1; i <= n; ++i) {
		if (a[i] & 1) {
			n_odd++;
			if (i >= 2 && (a[i - 1] & 1)) found_pairs = true;
			if (i >= 3 && (a[i - 2] & 1)) found_pairs = true;
		}
		if (b[i] & 1) {
			if (i >= 2 && (b[i - 1] & 1)) found_b = true;
			if (i >= 3 && (b[i - 2] & 1)) found_b = true;
		}
	}
	if (n_odd == n) {
		bool res = true;
		for (int i = 1; i <= n; ++i) {
			if (a[i] != b[i]) {
				res = false;
			}
		}
		if (res) {
			cout << "Yes" << endl;
		} else cout << "No" << endl;
		return 0;
	}
	if (found_pairs) {
		if (found_b) {
			vector <int> current_a, current_b;
			current_a.clear();
			current_b.clear();
			for (int i = 1; i <= n; ++i) {
				if (a[i] % 2 == 0) {
					current_a.push_back(a[i]);
				}
				if (b[i] % 2 == 0) {
					current_b.push_back(b[i]);
				}
			}
			if (current_a.size() > 2) {
				sort(current_a.begin(), current_a.end());
				sort(current_b.begin(), current_b.end());
			}
			bool good = true;
			for (int j = 0; j < current_a.size(); ++j) {
				if (current_a[j] != current_b[j])
					good = false;
			}
			if (current_a.size() != current_b.size())
				good = false;
			current_a.clear();
			current_b.clear();
			for (int i = 1; i <= n; ++i) {
				if (a[i] % 2 == 1) {
					current_a.push_back(a[i]);
				}
				if (b[i] % 2 == 1) {
					current_b.push_back(b[i]);
				}
			}
			for (int j = 0; j < current_a.size(); ++j) {
				if (current_a[j] != current_b[j])
					good = false;
			}
			if (current_a.size() != current_b.size())
				good = false;
			
			if (good) {
				cout << "Yes" << endl;
			} else cout << "No" << endl;
		} else cout << "No" << endl;
		return 0;
	}
	a[n + 1] = 1;
	b[n + 1] = 1;
	n++;
	int i = 1;
	vector <int> current_a, current_b;
	current_a.clear();
	current_b.clear();
	while (i <= n) {
		while (a[i] % 2 == 0) {
			current_a.push_back(a[i]);
			current_b.push_back(b[i]);
			i++;
		}
		if (a[i] != b[i]) {
			cout << "No" << endl;
			return 0;
		}
		if (current_a.size() > 2) {
			sort(current_a.begin(), current_a.end());
			sort(current_b.begin(), current_b.end());
		}
		for (int j = 0; j < current_a.size(); ++j) {
			if (current_a[j] != current_b[j]) {
				cout << "No" << endl;
				return 0;
			}
		}
		current_a.clear();
		current_b.clear();
		i++;
	}

	cout << "Yes" << endl;
	

	return 0;
}