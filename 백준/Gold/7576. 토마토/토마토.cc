#include<bits/stdc++.h>
using namespace std;
int m, n;
int a[1004][1004];
queue<pair<int, int>> q;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int visited[1004][1004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				q.push({ i,j }); visited[i][j] = 1;
			}
		}
	}
	int ret = 0;
	while (!q.empty()) {
		int y = q.front().first; int x = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i]; int nx = x + dx[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (a[ny][nx] == 0) { 
				a[ny][nx] = 1; q.push({ ny,nx }); 
				visited[ny][nx] = visited[y][x] + 1; 
				ret = max(ret, visited[ny][nx] - 1);
			}
		}

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				ret = -1; break;
			}
		}
	}
	cout << ret;
	return 0;
}