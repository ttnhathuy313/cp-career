#include<bits/stdc++.h>


using namespace std;
#define double long double
#define temp first
#define cap second
typedef pair <double, double> pdd;
 
const int N = 2e5+7;
const double EPS = 1e-8;
pdd tap[N];
int n;
double T;
 
bool check(double total)
{
	double mn = 0, left = total;
	for (int i=0; i<n; i++) {
		double flow = min(tap[i].cap, left);
		left -= flow;
		mn += flow * tap[i].temp;
	}
 
 
	double mx = 0; left = total;
	for (int i=n-1; i>=0; i--) {
		double flow = min(tap[i].cap, left);
		left -= flow;
		mx += flow * tap[i].temp;
	}
 
	double target = total * T;
 
	return (mn<=target && target<=mx);
}
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);
	cin >> n >> T;
	double total = 0;
 
	for (int i = 0; i < n; i++)
		cin >> tap[i].cap,
		total += tap[i].cap;
 
	for (int i = 0; i < n; i++)
		cin >> tap[i].temp;
 
	sort(tap, tap + n);
 
	double lo = 0, hi = total;
	while (abs(hi - lo) > EPS) {
		double mid = (lo + hi)/2;
		if (check(mid))		lo = mid;
		else				hi = mid;
	}
	cout << fixed << setprecision(9) << lo;

	return 0;
}