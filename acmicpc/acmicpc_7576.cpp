#include <iostream>
#include <queue>
#include <utility>
#include <bits/stdc++.h>

using namespace std;

int d[1001][1001];  // �ش� index�� �丶�䰡 �ʹµ� �ɸ��� ��¥ 
int tomato[1001][1001];  // �丶���� ���� ����(-1, 0, 1) 
int dx[4] = {0, 0, 1, -1};  // �� �� �� �� 
int dy[4] = {1, -1, 0, 0};  // �� �� �� �� 

int max(int a, int b) {
	return (a >= b) ? a : b;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int M, N;
	
	cin >> M >> N;
	
	queue<pair<int, int> > q;
	
	// tomato �迭�� �丶�� �Է� �ޱ� 
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			 
			d[i][j] = -1;
			if(tomato[i][j] == 1) {
				// queue�� ���� �丶���� ��ġ ���� 
				q.push({i,j});
				d[i][j] = 0;
			}
		}
	}
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		// �Ʒ��� ���� �丶�� ���� �� �� �� �¸� �˻��Ѵ�. 
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i]; // �� �� �� ���� x��ǥ nx�� ���� 
			int ny = y + dy[i]; // �� �� �� ���� y��ǥ ny�� ���� 
			
			// �Ʒ� if���� tomato[nx][ny]�� tomato�迭 ���� �ִ�����
			// �˻��Ѵ�. 
			if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
				
				// �丶�䰡 �ش� ��ġ�� �����ϰ�, ���� �ʾҴٸ� 
				if(tomato[nx][ny] == 0 && d[nx][ny] == -1) {
					
					// ���� �丶�亸�� �� �� �� ���� �丶���
					// �ʹµ� �Ϸ� �� �� �ɸ��Ƿ� +1�� ���ش�. 
					d[nx][ny] = d[x][y] + 1;
					// bfs�� ���� �ش� ��ǥ�� q�� �־��ش�. 
					q.push({nx, ny});
				}
			}
		}
	}
	
	int res = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			// d�迭(�ʹµ� �ɸ��� �ϼ��� ����� �迭)
			// �� ��� ���鼭 res�� �ִ� �ϼ���
			// �����Ѵ�. 
			res = max(res, d[i][j]);
		}
	}
	
	// �丶�䰡 ��� ���� ���ϴ� ��Ȳ �˻� 
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
