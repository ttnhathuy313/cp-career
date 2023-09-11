#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

/*
	Voi moi i, tim j lon nhat <= i sao cho [i, n] >= [j, j + n - i];

*/

const int N = 1e5 + 5;
int n, suf[N];
ii a[N], b[N];

int cnt(int x, int y) {
    if (x > y) return 1;
    if (x < y) return -1;
    return 0;
}

void sub1() {
	int l = 1, r = n;
    int cost = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i].first <= b[l].first) {
            cout << a[i].second << ' ' << b[r].second << endl;
            r--;
            continue;
        }
        if (a[i].first > b[l].first) {
            cout << a[i].second << ' ' << b[l].second << endl;
            l++;
        }
    }
}

void sub2() {
	int l = 1, r = n;
	for (int i = 1; i <= n; ++i) {

    	if (a[i].first == b[l].first) {
    		if (suf[i + 1] > l) {
    			cout << a[i].second << ' ' << b[l].second << endl;
    			l++;
    		} else {
    			cout << a[i].second << ' ' << b[r].second << endl;
            	r--;
    		}
    		continue;
    	}

        if (a[i].first < b[l].first) {
            cout << a[i].second << ' ' << b[r].second << endl;
            r--;
            continue;
        }
        if (a[i].first > b[l].first) {
            cout << a[i].second << ' ' << b[l].second << endl;
            l++;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("RACE.INP", "r", stdin);
    freopen("RACE.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i].first;
        b[i].second = i;
    }

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    suf[n + 1] = n + 1;
    for (int i = n; i >= 1; --i) {
    	if (b[1] > a[i]) {
    		suf[i] = -1;
    		continue;
    	}
    	int j = upper_bound(b + 1, b + 1 + n, a[i]) - b - 1;
    	suf[i] = min(j, suf[i + 1] - 1);
    }

    int l = 1, r = n;
    int cost = 0;
    for (int i = 1; i <= n; ++i) {

    	if (a[i].first == b[l].first) {
    		if (suf[i + 1] > l) {
    			// cout << a[i].second << ' ' << b[l].second << endl;
    			l++;
    		} else {
    			// cout << a[i].second << ' ' << b[r].second << endl;
    			cost += cnt(a[i].first, b[r].first);
            	r--;
    		}
    		continue;
    	}

        if (a[i].first < b[l].first) {
            // cout << a[i].second << ' ' << b[r].second << endl;
            cost += cnt(a[i].first, b[r].first);
            r--;
            continue;
        }
        if (a[i].first > b[l].first) {
            // cout << a[i].second << ' ' << b[l].second << endl;
            cost += cnt(a[i].first, b[l].first);
            l++;
        }
    }
    l = 1, r = n;
    int tmp = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i].first <= b[l].first) {
            tmp += cnt(a[i].first, b[r].first);
            r--;
            continue;
        }
        if (a[i].first > b[l].first) {
            tmp += cnt(a[i].first, b[l].first);
            l++;
        }
    }
    if (tmp > cost) sub1();
    else sub2();

    return 0;
}
