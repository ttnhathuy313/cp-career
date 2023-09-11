#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define fi   first
#define se   second
#define make_pair make_pair
#define all(a) a.begin(), a.end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define endl '\n'

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	clock_t tStart = clock();
	freopen("List.INP", "r", stdin);
	freopen("List.OUT", "w", stdout);

	vector <pair <int, string>> ds;

	// Data Structure
	ds.push_back(make_pair(0, "HLD"));
	ds.push_back(make_pair(0, "Centroid Decomposition"));
	ds.push_back(make_pair(1, "BIT 1D, BIT2D"));
	ds.push_back(make_pair(0, "Segment Tree (1D, 2D, Persistent)"));
	ds.push_back(make_pair(0, "Disjoint Set Union"));
	ds.push_back(make_pair(0, "Sparse Table"));
	ds.push_back(make_pair(0, "Sqrt Decomposition"));
	ds.push_back(make_pair(0, "Splay fuck"));
	ds.push_back(make_pair(3, "Deque / Stack"));
	ds.push_back(make_pair(1, "Hashing"));
	ds.push_back(make_pair(1, "Big Number"));
	ds.push_back(make_pair(0, "Aho Corasick"));
	ds.push_back(make_pair(0, "Knuth-Morris-Pratt"));

	// Technique
	ds.push_back(make_pair(0, "Parallel Binary Search"));
	ds.push_back(make_pair(2, "Dynamic Programming Simple"));
	ds.push_back(make_pair(0, "Dynamic Programming Lexicographically"));
	ds.push_back(make_pair(0, "Dynamic Programming Digit"));
	ds.push_back(make_pair(2, "Dynamic Programming On Tree"));
	ds.push_back(make_pair(1, "Dynamic Programming Optimization / + Greedy Observations"));
	ds.push_back(make_pair(0, "Dynamic Programming Bitmask"));
	ds.push_back(make_pair(0, "Dynamic Programming On Broken Profile"));
	ds.push_back(make_pair(5, "Fucking Greedy"));
	ds.push_back(make_pair(0, "Divide and Conquer"));
	ds.push_back(make_pair(1, "Two Pointers"));
	ds.push_back(make_pair(2, "bRutE fOrcE"));
	ds.push_back(make_pair(3, "Binary Search"));
	ds.push_back(make_pair(0, "Meet in the middle"));

	// Math
	ds.push_back(make_pair(0, "Number Sequence"));
	ds.push_back(make_pair(0, "Geometric Progression"));
	ds.push_back(make_pair(1, "Combinatorics"));
	ds.push_back(make_pair(2, "Inverse Modulo"));
	ds.push_back(make_pair(0, "Euler Totient Function"));
	ds.push_back(make_pair(0, "Linear Diophantine Equation"));
	ds.push_back(make_pair(0, "Matrix Multiplycation"));
	ds.push_back(make_pair(1, "Cayley's Formula"));
	ds.push_back(make_pair(1, "Inclusion Exclusion Principle"));
	ds.push_back(make_pair(0, "Gaussian Elimination"));

	//Graph
	ds.push_back(make_pair(0, "Dijkstra Algo"));
	ds.push_back(make_pair(1, "Bellman Ford"));
	ds.push_back(make_pair(2, "Tarjan Algo"));
	ds.push_back(make_pair(0, "Floyd Algo"));
	ds.push_back(make_pair(0, "Dynamic Connectivity Probs"));
	ds.push_back(make_pair(1, "2edge Connectivity"));
	ds.push_back(make_pair(1, "2Vertex Connectivity"));
	ds.push_back(make_pair(2, "DAG and Topological Sortings"));
	ds.push_back(make_pair(0, "Minimum Spanning Tree"));
	ds.push_back(make_pair(0, "Euler Circuit"));
	ds.push_back(make_pair(0, "MaxFlow and Related Probs"));
	ds.push_back(make_pair(0, "Maximum Matching on Biparite Graph"));
	ds.push_back(make_pair(0, "2Sat"));
	ds.push_back(make_pair(0, "Johnson Algo"));
	ds.push_back(make_pair(0, "Euler Tour on Tree"));

	//Geometry
	ds.push_back(make_pair(0, "SweepLine"));
	ds.push_back(make_pair(0, "Basic Geometry"));
	ds.push_back(make_pair(2, "Convex Hull"));
	ds.push_back(make_pair(2, "Polygon"));
	ds.push_back(make_pair(0, "Pick's Theorem"));

	sort(all(ds));
	int id = 0;
	for (auto d : ds) {
		id++;
		cout << id << ". " << d.second << endl;
	}

	fprintf(stderr, "Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
