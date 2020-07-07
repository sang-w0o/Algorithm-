#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool visited[101];
int depth[101];

void bfs(int **adj, int vertex, int size, queue<int> q) {

	visited[vertex] = true;
	q.push(vertex);

	while (!q.empty()) {
		vertex = q.front();
		q.pop();

		for (int i = 1; i <= size; i++) {
			if (adj[vertex][i] && !visited[i]) {
				q.push(i);
				depth[i] = depth[vertex] + 1;
				visited[i] = true;
			}
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	queue<int> q;

	int **persons;
	persons = new int *[n + 1];
	for (int i = 0; i <= n; i++) {
		persons[i] = new int[n + 1];
	}
	memset(persons, 0, sizeof(persons));

	int p1, p2;
	cin >> p1 >> p2;
	int m;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		persons[x][y] = 1;
		persons[y][x] = 1;
	}
	bfs(persons, p1, n, q);
	
	if (depth[p2]) {
		cout << depth[p2] << '\n';
	}
	else {
		cout << -1 << '\n';
	}
	delete[] persons;
}