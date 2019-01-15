#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 99999

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

struct point {
	int x, y, h;
	point(int x, int y, int h) : x(x), y(y), h(h) {};
};

int bfs(vector<vector<char>> mat, int vx, int vy, int ex, int ey) {
	queue<point> q;
	vector<bool> visited;
	int min_level = INF, level = 0;

	visited.resize(mat.size(), mat[0].size());
	fill(visited.begin(), visited.end(), false);

	q.push(point(vx, vy, 0));
	visited[vx * mat.size() + vy] = true;

	while (!q.empty()) {
		int n = q.size();

		for (int i = 0; i < n; i++) {
			int vx = q.front().x, vy = q.front().y, vh = q.front().h;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int x = vx + dx[j], y = vy + dy[j];
				if (x < 0 || x >= mat.size() || y < 0 || y >= mat[0].size())
					continue;

				int next = x * mat.size() + y;
				if (mat[x][y] != 'M' && (min_level > level || !visited[next])) {
					int h = (mat[x][y] == 'H') ? vh + 1 : vh;
					if (h < 2) {
						q.push(point(x, y, h));
						visited[next] = true;
						if (x == ex && y == ey && min_level > level)
							min_level = level;
					}
				}
			}
		}
		level++;
	}
	return min_level + 1;
}

int main() {
	cin.sync_with_stdio(false);
	vector<vector<char>> mat;
	int n, m;
	int sx, sy, ex, ey;
	cout << "row col sx sy ex ey" << '\n';
	cin >> n >> m >> sx >> sy >> ex >> ey;
	mat.resize(n);
	for (int i = 0; i < n; i++) {
		mat[i].resize(m);
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];
	}

	cout << bfs(mat, sx, sy, ex, ey);
}
