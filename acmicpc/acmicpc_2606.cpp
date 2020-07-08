#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool visited[101];
int res = 0;

void bfs(int **adj, int v, int size, queue<int> q) {
	visited[v] = true;
	q.push(v);

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 1; i <= size; i++) {
			if (adj[v][i] && !visited[i]) {
				q.push(i);
				++res;
				visited[i] = true;
			}
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int N;
	int M;

	cin >> N >> M;
	
	int **adj;
	adj = new int *[N + 1];
	for (int i = 0; i <= N; i++) {
		adj[i] = new int[N + 1];
	}
	
	while (M--) {
		int x, y;
		cin >> x >> y;
		adj[x][y] = 1;
		adj[y][x] = 1;
	}

	queue<int> q;
	bfs(adj, 1, N, q);

	cout << res << '\n';
}