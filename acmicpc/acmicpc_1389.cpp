#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// bfs���� �湮���θ� Ȯ���ϱ� ���� �迭 
bool visited[101];

// bfs�� ȣ��� �� ���� �� vertex�� bacon �� ���� 
int bacons[101];

// ���� ����� �����ϴ� �迭 
int results[101];

void bfs(int **adj, int vertex, int size, queue<int> q) {
	
	visited[vertex] = true;
	q.push(vertex);
	int tmp;
	
	while(!q.empty()) {
		tmp = q.front();
		q.pop();
		
		for(int i = 1; i <= size; i++) {
			if(adj[tmp][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
				// i���� tmp�� �� �� �����Ƿ� 
				// i�� +1�� ���ش�. 
				bacons[i] = bacons[tmp] + 1;
			}
		}
	}
}

int main() {
	
	int N, M;
	cin >> N >> M;
	
	int **adj = new int*[N+1];
	for(int i = 0; i <= N; i++) {
		adj[i] = new int[N+1];
	}
	
	while(M--) {
		int x,y;
		cin >> x >> y;
		adj[x][y] = 1;
		adj[y][x] = 1;
	}
	
	queue<int> q;
	
	for(int i = 1; i <= N; i++) {
		bfs(adj, i, N, q);
		// for�� ���鼭 bfs�� ��� ȣ���ϹǷ�, visited�迭��
		// false�� �ʱ�ȭ�Ѵ�. 
		memset(visited, false, sizeof(visited));
		
		// i�� 1~N������ ������ ���� results�迭�� ����
		// bfs�� �ٽ� ȣ��ǹǷ� bacons[j] = 0 ���ش�. 
		for(int j = 1; j <= N; j++) {
			results[i] += bacons[j];
			bacons[j] = 0;
		}
	}
	
	int min = results[1];
	int res = 1;
	
	for(int i = 2; i <= N; i++) {
		if(min > results[i]){
			min = results[i];
			res = i;
		}
	}
	
	cout << res << '\n';
	
	// �޸� ����
	for(int i = 0; i <= N; i++) {
		delete[] adj[i];
	} 
	
	delete[] adj;
	
	return 0;
	
}
