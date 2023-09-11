#include <bits/stdc++.h>

using namespace std;

const int N = 505;

template <typename T>
pair <T, vector <int>> Hungarian (int n, int m, T c[N][N]) {
  vector <T> v(m), dist(m);        
  vector <int> L(n, -1), R(m, -1);
  vector <int> index(m), prev(m);
  auto residue = [&] (int i, int j) {return c[i][j] - v[j];};

  iota(index.begin(), index.end(), 0);
  for (int f = 0; f < n; ++f) {
    for (int j = 0; j < m; ++j) {
      dist[j] = residue(f, j), prev[j] = f;
    }
    T w; int i, j, l, s = 0, t = 0;
    while (true) {
      if (s == t) {
        l = s, w = dist[index[t++]];
        for (int k = t; k < m; ++k) {
          j = index[k]; T h = dist[j];
          if (h <= w) {
            if (h < w) t = s, w = h;
            index[k] = index[t], index[t++] = j;
          }
        }
        for (int k = s; k < t; ++k) {
          j = index[k];
          if (R[j] < 0) goto augment;
        }
      }
      int q = index[s++], i = R[q];
      for (int k = t; k < m; ++k) {
        j = index[k];
        T h = residue(i, j) - residue(i, q) + w;
        if (h < dist[j]) {
          dist[j] = h, prev[j] = i;
          if (h == w) {
            if (R[j] < 0) goto augment;
            index[k] = index[t], index[t++] = j;
          }
        }
      }
    }
  augment:
    for (int k = 0; k < l; ++k) v[index[k]] += dist[index[k]] - w;
    do {
      R[j] = i = prev[j], swap(j, L[i]);
    } while (i ^ f);
  }
  T ret = 0;
  for (int i = 0; i < n; ++i) ret += c[i][L[i]];
  return {ret, L};
}

int n; 
long long a[N][N];
long long cost[N][N];

int main() {
	// freopen("TaskH.inp", "r", stdin);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) scanf("%lld", a[i] + j);
  }
  int totNode = (n + 1) >> 1;
  for (int i = 0; i < totNode; ++i) {
  	int pos = i * 2;
  	for (int j = 0; j < totNode; ++j) {
  		int cur = j * 2;
  		cost[j][i] = (pos ? a[cur][pos - 1] : 0) + a[cur][pos + 1];
  	}
  }
  long long ans = Hungarian(totNode, totNode, cost).first;
  cout << ans << '\n';
  
  return 0;
}