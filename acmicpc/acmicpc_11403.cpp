#include <iostream>
#include <queue>
using namespace std;

void bfs(int **adj, int vertex, int size) {
	
	int visited[101] = {0, };
	
	queue<int> q;
	
	q.push(vertex);
	
	while(!q.empty()) {
		int tmp = q.front();
		q.pop();
		for(int i = 1; i <= size; i++) {
			// �Ʒ� if���� tmp�� i ������ ������ �ְ�,
			// i��°�� �湮������ ���ٸ� ����ȴ�. 
			if(adj[tmp][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
				adj[vertex][i] = 1;
			}	
		}
	}
} 

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
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
	
	for(int i = 1; i <= N; i++) {
		bfs(adj, i, N);
	}
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cout << adj[i][j] << " ";
		}
		cout << '\n';
	}
	
	for(int i = 0; i <= N; i++) {
		delete[] adj[i];
	}
	
	delete[] adj;
	
	return 0;
	
}
