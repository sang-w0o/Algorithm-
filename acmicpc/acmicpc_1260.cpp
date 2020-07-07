#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

bool visited[1001];

void dfs(int **adj, int vertex, int size) {
	cout << vertex << " ";
	visited[vertex] = true;
	for (int i = 1; i <= size; i++) {
		if (adj[vertex][i] && !visited[i]) {
			dfs(adj, i, size);
		}
	}
}

void bfs(int **adj, int vertex, int size, queue<int> q) {
	visited[vertex] = true;
	q.push(vertex);

	while (!q.empty()) {
		vertex = q.front();
		q.pop();
		cout << vertex << " ";
		for (int i = 1; i <= size; i++) {
			if (adj[vertex][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, V;

	cin >> N >> M >> V;

	queue<int> q;


	int **adj;
	adj = new int *[N + 1];
	for (int i = 0; i <= N; i++) {
		adj[i] = new int[N + 1];
	}

	memset(adj, 0, sizeof(adj));
	memset(visited, false, sizeof(visited));


	while (M--) {
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1][v2] = 1;
		adj[v2][v1] = 1;
	}

	dfs(adj, V, N);
	cout << '\n';
	
	memset(visited, false, sizeof(visited));
	memset(adj, 0, sizeof(adj));
	bfs(adj, V, N, q);

	delete[] adj;
}