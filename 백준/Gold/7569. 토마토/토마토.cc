#include<bits/stdc++.h>
using namespace std;
int m, n, h, y, x, z, nx, ny, nz;
int a[104][104][104];
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
int ret = 1;
struct trip {
	int x, y, z;
};
vector<trip> ones;
int visited[104][104][104];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n >> h;
	for (int z = 0; z < h; z++)
		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++) {
				cin >> a[x][y][z];
				if (a[x][y][z] == 1) ones.push_back({ x,y,z });
			}
	queue<trip> q;
	for (trip one : ones) {
		q.push(one); visited[one.x][one.y][one.z] = 1;
	}
	while (!q.empty()) {
		x = q.front().x; y = q.front().y; z = q.front().z;
		q.pop();
		for (int i = 0; i < 6; i++) {
			nx = dx[i] + x; ny = dy[i] + y; nz = dz[i] + z;
			if (nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= h) continue;
			if (a[nx][ny][nz] == -1|| visited[nx][ny][nz]) continue;
			visited[nx][ny][nz] = visited[x][y][z] + 1;
			q.push({ nx,ny,nz });
			ret = max(ret, visited[nx][ny][nz]);
		}
	}
	for (int z = 0; z < h; z++)
		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++) {
				if (a[x][y][z] == 0&&visited[x][y][z]==0) {
					cout << -1; return 0;
				}
			}
	cout << ret-1;
	return 0;
}