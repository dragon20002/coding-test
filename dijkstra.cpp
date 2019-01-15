#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> int_pair; //distance, destination vertex

int dijkstra(vector<vector<int>> mat, int s, int e) {
	vector<int> dist, prev;
	vector<bool> visited;
	priority_queue<int_pair, vector<int_pair>, greater<int_pair>> pq;
			// int_pair's first(distance) min heap

	dist.resize(mat.size());
	for (int i = 0; i < mat.size(); i++)
		dist[i] = mat[s][i];
	prev.resize(mat.size());
	fill(prev.begin(), prev.end(), -1);
	visited.resize(mat.size());
	fill(visited.begin(), visited.end(), false);

	dist[s] = 0;
	pq.push(int_pair(0, s));
	while (!pq.empty()) {
		int u;
		do {
			u = pq.top().second; pq.pop();
		} while (!pq.empty() && visited[u]);

		if (visited[u]) break;

		visited[u] = true;

		for (int v = 0; v < mat.size(); v++) {
			if (!visited[v]) {
				int tmp = dist[u] + mat[u][v];
				if (dist[v] > tmp) {
					dist[v] = tmp;
					prev[v] = u;
				}
				pq.push(int_pair(dist[v], v));
			}
		}
	}

	return dist[e];
}

int main() {
	cin.sync_with_stdio(false);
	vector<vector<int>> mat;
	int n;

	cin >> n;
	mat.resize(n);
	for (int i = 0; i < n; i++) {
		mat[i].resize(n);
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];
	}

	for (int i = 0; i < n; i++)
		cout << dijkstra(mat, 0, i) << '\n';
}
