#include <stdio.h>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

vector<list<int>> adj;
vector<bool> visited;
list<int> q;

void dfs(int v) {
	visited[v] = true;
	printf("%d ", v);

	for (int next : adj[v])
		if (!visited[next])
			dfs(next);
}

void bfs(int v) {
	q.push_back(v);
	visited[v] = true;

	while (!q.empty()) {
		int n = q.size();

		for (int i = 0; i < n; i++) {
			v = q.front();
			printf("%d ", v);
			q.pop_front();

			for (int next : adj[v]) {
				if (!visited[next]) {
					q.push_back(next);
					visited[next] = true;
				}
			}
		}
	}
}

int main() {
	int nN, nE, start;
	
	scanf("%d %d %d", &nN, &nE, &start);
	nN++;

	adj.resize(nN);
	visited.resize(nN);

	while (nE--) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i < nN; i++)
		adj[i].sort();

	fill(visited.begin(), visited.end(), false);
	dfs(start);

	printf("\n");

	fill(visited.begin(), visited.end(), false);
	bfs(start);
}
