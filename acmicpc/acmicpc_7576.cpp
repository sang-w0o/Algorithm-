#include <iostream>
#include <queue>
#include <utility>
#include <bits/stdc++.h>

using namespace std;

int d[1001][1001];  // 해당 index의 토마토가 익는데 걸리는 날짜 
int tomato[1001][1001];  // 토마토의 상태 저장(-1, 0, 1) 
int dx[4] = {0, 0, 1, -1};  // 상 하 우 좌 
int dy[4] = {1, -1, 0, 0};  // 상 하 우 좌 

int max(int a, int b) {
	return (a >= b) ? a : b;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int M, N;
	
	cin >> M >> N;
	
	queue<pair<int, int> > q;
	
	// tomato 배열에 토마토 입력 받기 
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			 
			d[i][j] = -1;
			if(tomato[i][j] == 1) {
				// queue에 익은 토마토의 위치 삽입 
				q.push({i,j});
				d[i][j] = 0;
			}
		}
	}
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		// 아래는 익은 토마토 기준 상 하 우 좌를 검사한다. 
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i]; // 상 하 우 좌의 x좌표 nx에 저장 
			int ny = y + dy[i]; // 상 하 우 좌의 y좌표 ny에 저장 
			
			// 아래 if문은 tomato[nx][ny]가 tomato배열 내에 있는지를
			// 검사한다. 
			if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
				
				// 토마토가 해당 위치에 존재하고, 익지 않았다면 
				if(tomato[nx][ny] == 0 && d[nx][ny] == -1) {
					
					// 기준 토마토보다 상 하 우 좌의 토마토는
					// 익는데 하루 가 더 걸리므로 +1을 해준다. 
					d[nx][ny] = d[x][y] + 1;
					// bfs를 위해 해당 좌표를 q에 넣어준다. 
					q.push({nx, ny});
				}
			}
		}
	}
	
	int res = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			// d배열(익는데 걸리는 일수가 저장된 배열)
			// 을 모두 돌면서 res에 최대 일수를
			// 저장한다. 
			res = max(res, d[i][j]);
		}
	}
	
	// 토마토가 모두 익지 못하는 상황 검사 
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(tomato[i][j] == 0 && d[i][j] == -1) {
				res = -1;
			}
		}
	}
	
	cout << res;
	return 0;
	
	
	
}
