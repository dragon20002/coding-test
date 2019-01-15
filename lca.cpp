#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int p[40001];
int h[40001];
bool visited[40001];
vector<vector<pair<int, int>>> v(40001);

void bfs(int start) {
	p[start] = start;
	h[start] = 1;
	visited[start] = true;

	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int w = v[now][i].second;

			if (!visited[next]) {
				p[next] = now;
				h[next] = h[now] + 1;
				visited[next] = true;
				q.push(next);
			}
		}
	}
}
int lca(int a, int b, int sum) {
	while (h[a] != h[b]) {
		if (h[a] > h[b]) {
			for (int i = 0; i < v[a].size(); i++) {
				if (v[a][i].first == p[a]) {
					sum += v[a][i].second;
					break;
				}
			}

			a = p[a];
		}
		else {
			for (int i = 0; i < v[b].size(); i++) {
				if (v[b][i].first == p[b]) {
					sum++;
					break;
				}
			}

			b = p[b];
		}
	}


	while (a != b) {
		for (int i = 0; i < v[a].size(); i++) {
			if (v[a][i].first == p[a]) {
				sum++;
				break;
			}
		}
		for (int i = 0; i < v[b].size(); i++) {
			if (v[b][i].first == p[b]) {
				sum++;
				break;
			}
		}

		a = p[a];
		b = p[b];
	}

	return sum;
}

int main() {
	int n, m;
	scanf("%d", &n);
	vector<int> ans;

	for (int i = 1; i < n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	bfs(1);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		ans.push_back(lca(a, b, 0));
	}

	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}
