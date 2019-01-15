#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
using namespace std;

int n;
int** map;
vector<bool> visited;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int dfs(int cx, int cy) {
	visited[cx * n + cy] = true;

	int cs = 1;

	for (int i = 0; i < 4; i++) {
		int x = dx[i] + cx, y = dy[i] + cy;
		if (x < 0 || x >= n || y < 0 || y >= n)
			continue;

		if (!visited[x * n + y] && map[x][y] == 1)
			cs += dfs(x, y);
	}
	return cs;
}


int main() {
	scanf("%d", &n);

	map = new int*[n];
	visited.resize(n * n);

	for (int i = 0; i < n; i++) {
		map[i] = new int[n];
		for (int j = 0; j < n; j++) {
			int v;
			scanf("%d", &map[i][j]);
		}
	}

	list<int> comp_sizes;
	fill(visited.begin(), visited.end(), false);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (!visited[i * n + j] && map[i][j] == 1) {
				comp_sizes.push_back(dfs(i, j));
			}
		}

	cout << comp_sizes.size() << endl;
	comp_sizes.sort();
	for (int cs : comp_sizes)
		cout << cs << ' ';
	cout << endl;
}
