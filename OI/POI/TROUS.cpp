#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e6 + 5;
int n, p, d, a[N], pref[N];


void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 

bool check(int len) {
	int range = len - d + 1;
	deque <int> st; st.clear();
	for (int i = d; i <= n; ++i) {
		while (!st.empty() && pref[st.back()] - pref[st.back() - d] < pref[i] - pref[i - d])
			st.pop_back();
		st.push_back(i);
		while (!st.empty() && i - st.front() + 1 > range)
			st.pop_front();
		if (i < len) continue;
		int val = pref[st.front()] - pref[st.front() - d];
		int tot = pref[i] - pref[i - len];
		if (tot - val <= p) return true;
	}
	return false;
}

signed main() {
	freopen("TROUS.INP", "r", stdin);
	freopen("TROUS.OUT", "w", stdout);

	fastscan(n); fastscan(p); fastscan(d);
	for (int i = 1; i <= n; ++i) {
		fastscan(a[i]);
		pref[i] = pref[i - 1] + a[i];
	}
	int l = d, r = n, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	printf("%d\n", ans);

	return 0;
}