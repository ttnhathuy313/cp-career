struct Edge {
	Edge() {x = y = c = f = w = 0;}
	Edge(int _x, int _y, int _c, int _f, int _w) : x(_x), y(_y), c(_c), f(_f), w(_w) {}
	int x, y, c, f, w;
};

struct MinCostMaxFlow {
	int n, m, idm = 0, s, t;
	int totCost, totFlow, oo = int(1e9);
	vector <Edge> EdgeList;
	vector <int> dist;
	vector <vector <int>> adj;
	vector <int> trace;
 
	MinCostMaxFlow() {
		n = 0;
	}
 
	MinCostMaxFlow(int n) {
		this -> n = n;
		adj.assign(n + 5, vector <int> (0, 0));
		EdgeList.clear();
		dist = vector <int> (n + 5);
		trace = vector <int> (n + 5);
	}
 
 
	void addEdge(int u, int v, int c, int w) {
		adj[u].push_back(EdgeList.size());
		EdgeList.push_back(Edge(u, v, c, 0, w));
		adj[v].push_back(EdgeList.size());
		EdgeList.push_back(Edge(v, u, 0, 0, -w));
	}
 
	bool FordBellman(int s, int t) {
		for (int i = 1; i <= n; ++i) dist[i] = oo, trace[i] = -1;
		vector <bool> inq = vector <bool> (n + 5, false);
		queue <int> q;
		q.push(s); inq[s] = true; dist[s] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop(); inq[u] = false;
			for (int id : adj[u]) if (EdgeList[id].c > EdgeList[id].f) {
				int v = EdgeList[id].y;
				if (dist[v] > dist[u] + EdgeList[id].w) {
					dist[v] = dist[u] + EdgeList[id].w;
					trace[v] = id;
					if (!inq[v]) {
						q.push(v);
						inq[v] = true;
					}
				}
			}
		}
		return (dist[t] < oo);
	}
	
	void solve() {
		totFlow = totCost = 0;
		while (FordBellman(s, t)) {
			int delta = oo;
			for (int u = t; u != s; u = EdgeList[trace[u]].x) 
				delta = min(delta, EdgeList[trace[u]].c - EdgeList[trace[u]].f);
			for (int u = t; u != s; u = EdgeList[trace[u]].x) {
				EdgeList[trace[u]].f += delta;
				EdgeList[trace[u] ^ 1].f -= delta;
			}
			totCost += delta * dist[t];
			totFlow += delta;
		}
	}
 
};