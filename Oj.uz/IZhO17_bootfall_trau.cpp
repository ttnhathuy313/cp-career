#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e2 + 5;
const int S = N * N;
 
int cur [S];
int nxt [S];
 
int without [S];
 
bitset<S> ans;
bitset<S> Get;
 
int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("IZhO17_bootfall.INP", "r", stdin);
  freopen("IZhO17_bootfall.ANS", "w", stdout);
  int n;
  cin >> n;
  vector<int> a (n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int whole_sum = accumulate (a.begin(), a.end(), 0);
  cur[0] = nxt[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = a[i]; j < S; j++) {
      nxt[j] += cur[j - a[i]];
    }
    for (int j = 0; j < S; j++) {
      cur[j] = nxt[j];
    }
  }
  if ((whole_sum & 1) || (cur[whole_sum / 2] == 0) ) {
    cout << 0 << '\n';
    return 0;
  }
  ans.set();
  for (int i = 0; i < n; i++) {
    whole_sum -= a[i];
    for (int j = 0; j < S; j++) {
      without[j] = cur[j];
    }
    for (int j = a[i]; j < S; j++) {
      if (without[j]) without[j] -= without[j - a[i]];
    }
    Get.reset();
    for (int j = 0; j <= whole_sum; j++) {
      if (without[j]) {     
        int left = j;
        int right = whole_sum - j;
        Get[abs(left - right)] = 1;
      }
    }
    ans &= Get;
    whole_sum += a[i];
  } 
  cout << ans.count() << '\n';
  for (int i = 0; i < S; i++) if (ans[i]) cout << i << ' ';
  return 0;
}