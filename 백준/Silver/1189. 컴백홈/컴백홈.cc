#include<bits/stdc++.h>
using namespace std;
int r, c, k;
char a[6][6];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int visited[6][6];
int ret = 0;
void go(int y, int x,int now) {
	if (y == 0 && x == c - 1) {
		if (now == k) ret++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; int nx = x + dx[i];
		if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
		if (visited[ny][nx] || a[ny][nx]=='T') continue;
		visited[ny][nx] = 1;
		go(ny, nx, now + 1);
		visited[ny][nx] = 0;
	}
}
 int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) cin >> a[i][j];
	visited[r - 1][0] = 1; go(r - 1, 0, 1); 
	cout << ret;
	return 0;
}