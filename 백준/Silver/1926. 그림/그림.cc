#include<bits/stdc++.h>
using namespace std;
int n, m, ny, nx;
int a[504][504];
int visited[504][504];
int dy[4] = { -1,1,0,0 }; int dx[4] = { 0,0,-1,1 };
int ret1 = 0; int tem;
int ret2 = 0;
void go(int y, int x) {
	visited[y][x] = 1; tem++;
	for (int i = 0; i < 4; i++) {
		ny = dy[i] + y; nx = dx[i] + x;
		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if (a[ny][nx] == 0 || visited[ny][nx]) continue;
		go(ny, nx);
	}

	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> a[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 || visited[i][j]) continue;
			else {
				// 처음 방문
				tem = 0;
				ret1++; go(i, j);
				ret2 = max(ret2, tem);
			}
		}
	}
	cout << ret1 << "\n" << ret2;
	return 0;
}