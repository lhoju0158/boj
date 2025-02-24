#include<bits/stdc++.h>
using namespace std;
int n, m;
int jx, jy, cx, cy;
char a[304][304];
int visited[304][304];
int cnt = 0;
int dy[4] = { -1,1,0,0 }; int dx[4] = { 0,0,-1,1 };
string s;
// 0을 만나면 bfs 진행
// 1을 만나면 cnt++;
// 기존 bfs에 queue를 2개 사용하는 것
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> jy >> jx >> cy >> cx;
	jx--; jy--; cx--; cy--;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) a[i][j] = s[j];
	}
	visited[jy][jx] = 1;
	queue<int> q; q.push(1000 * jy + jx); // 모듈러 연산으로 표현하기
	while (a[cy][cx] != '0') {
		cnt++;
		queue<int>tem; // 1인 것들을 모으기
		while (!q.empty()) {
			int y = q.front() / 1000; int x = q.front() % 1000; q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i]; int nx = x + dx[i];
				if (nx<0 || ny<0 || nx>m || ny>n) continue;
				if (visited[ny][nx]) continue;
				visited[ny][nx] = cnt;
				if (a[ny][nx] != '0') {
					a[ny][nx] = '0'; tem.push(1000 * ny + nx);
				}
				else {
					q.push(1000 * ny + nx);
				}
			}
		}
		q = tem;
	}
	cout << visited[cy][cx];
	return 0;
}