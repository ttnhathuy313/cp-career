struct dsu_t { // add an edge to a new graph, the bipartiteness is stored in isBipartite
	int n, isBipartite, nVersion;
	stack <pair <int, int>> roll_back;
	vector <int> lab, Rank, parity;
	dsu_t() {}
	dsu_t(int _n) {
		this -> n = _n;
		isBipartite = true;
		nVersion = 0;
		lab.assign(n + 5, -1);
		Rank.assign(n + 5, 0);
		parity.assign(n + 5, 0);
		while (!roll_back.empty())
			roll_back.pop();
	}
	pair<int, int> root(int x) {
		if(lab[x] == -1)
			return {x, parity[x]};
		pair<int, int> p = root(lab[x]);
		p.second ^= parity[x];
		return p;
	}
	void merge(int u, int v) {
		pair <int, int> px = root(u), py = root(v);
		int rx = px.first, vx = px.second, ry = py.first, vy = py.second;
		if (rx == ry) {
			if (vx == vy) {
				roll_back.push(pair <int, int>(0, isBipartite));
				nVersion++;
				isBipartite = false;
			}
			return;
		}
		if (Rank[rx] > Rank[ry]) {
			swap(rx, ry);
			swap(vx, vy);
		}
		lab[rx] = ry;
		roll_back.push(pair <int, int>(3, rx + (parity[rx]) * n));
		roll_back.push(pair <int, int>(1, rx));
		nVersion += 2;
		parity[rx] = vx ^ vy ^ 1;
		if (Rank[rx] == Rank[ry]) roll_back.push(pair <int, int>(2, ry));
		nVersion += Rank[rx] == Rank[ry];
		Rank[ry] += (Rank[rx] == Rank[ry]);
	}
	void roll_to(int version) {
		while (nVersion != version) {
			pair <int, int> item = roll_back.top();
			roll_back.pop(); nVersion--;
			if (item.first == 0) {
				isBipartite = item.second;
			} else if (item.first == 1) {
				lab[item.second] = -1;
			} else if (item.first == 2) {
				Rank[item.second]--;
			} else if (item.first == 3) {
				if (item.second > n) {
					parity[item.second - n] = 1;
				} else parity[item.second] = 0;
			}
		}
	}
} dsu;