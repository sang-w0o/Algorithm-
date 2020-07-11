#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// bfs에서 방문여부를 확인하기 위한 배열 
bool visited[101];

// bfs가 호출될 때 마다 각 vertex의 bacon 수 저장 
int bacons[101];

// 최종 결과를 저장하는 배열 
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
				// i에서 tmp로 갈 수 있으므로 
				// i에 +1을 해준다. 
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
		// for문 돌면서 bfs를 계속 호출하므로, visited배열을
		// false로 초기화한다. 
		memset(visited, false, sizeof(visited));
		
		// i가 1~N까지의 베이컨 수를 results배열에 저장
		// bfs가 다시 호출되므로 bacons[j] = 0 해준다. 
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
	
	// 메모리 해제
	for(int i = 0; i <= N; i++) {
		delete[] adj[i];
	} 
	
	delete[] adj;
	
	return 0;
	
}
