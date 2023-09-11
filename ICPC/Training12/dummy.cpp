#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int to, id;
};

const int N = 1e5 + 5;
int n, m;
bool mark_edge[N];
vector <Edge> adj[N];

int start;
vector <Edge> edge_order[N];
void first_proof(int u) {
	for (Edge e : adj[u]) {
		if (!mark_edge[e.id]) {
			mark_edge[e.id] = true;
			edge_order[u].push_back(e);
			first_proof(e.to);
		}
	}
}
void print_euler_first_proof(int u) {
	cout << u << ' ';
	// traverse backward
	for (int i = edge_order[u].size() - 1; i >= 0; --i) {
		Edge e = edge_order[u][i];
		if (!mark_edge[e.id]) {
			mark_edge[e.id] = true;
			print_euler_first_proof(e.to);
		}
	}
}


stack <int> euler;
void second_proof(int u) {
	for (Edge e : adj[u]) {
		if (!mark_edge[e.id]) {
			mark_edge[e.id] = 1;
			// From the second iteration, if found another cycle edge set, 
			// follow it and merge with the current set.
			second_proof(e.to);
			euler.push(u);
		}
	}
}
void print_euler_second_proof() {
	int first = euler.top();
	while (!euler.empty()) {
		cout << euler.top() << ' ';
		euler.pop();
	}
	cout << first << endl;
}



int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("dummy.inp", "r", stdin);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}

	first_proof(1);
	memset(mark_edge, 0, sizeof mark_edge);
	print_euler_first_proof(1);
	cout << endl;
	
	memset(mark_edge, 0, sizeof mark_edge);
	second_proof(1);
	print_euler_second_proof();
	

	return 0;
}