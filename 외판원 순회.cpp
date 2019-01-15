#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
using namespace std;

int nv, ne;
vector< vector<int> > adj;
int *map;

int tsp(int cur, int visit) {
	if (visit == (1 << nv) - 1) {
		return 0;
	}

	int min_time = 2e9;
	for (int i = 0; i < adj[cur].size(); i++) {
		int node = adj[cur][i];
		if (!(visit & (1 << node))) {
			int time = tsp(node, visit | (1 << node));
			if (time != -1) {
				if (min_time > time + map[cur*nv + node])
					min_time = time + map[cur*nv + node];
			}
		}
	}

	return min_time;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> nv >> ne;
	adj.resize(nv);
	map = new int[nv * nv];
	memset(map, 0, sizeof(int) * (nv * nv));

	for (int i = 0; i < ne; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		s--; e--;
		adj[s].push_back(e);
		adj[e].push_back(s);
		map[s*nv + e] = map[e*nv + s] = w;
	}

	int min_sum = 2e9;
	for (int i = 0; i < nv; i++) {
		int sum = tsp(i, 1 << i);
		if (min_sum > sum)
			min_sum = sum;
	}

	cout << min_sum;
}
