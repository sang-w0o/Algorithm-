#include <iostream>
#include <cstring>

using namespace std;

bool visited[101];

void dfs(int **adj, int vertex, int size, queue<int> q) {
	
} 
int main() {
	
	int N;
	cin >> N;
	
	int **adj = new int *[N + 1];
	for(int i = 0; i <= N; i++) {
		adj[i] = new int[N + 1];
	}
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cin >> adj[i][j];
		}
	}
	
	queue<int> q;
	
	for(int i = 1; i <= N; i++) {
		bfs(adj, i, N, q);
		memset(visited, false, sizeof(visited));
		
	}
	
	
}
