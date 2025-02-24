#include<bits/stdc++.h>
using namespace std;
int r, c;
char a[24][24];
int visited[30];
string s;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ret = 1;
void go(int y, int x,int cnt) {
	ret = max(ret, cnt);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; int nx = x + dx[i];
		if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
		int _next = (int)a[ny][nx] - 'A';
		if (!visited[_next]) {
			visited[_next] = 1;
			go(ny, nx, cnt + 1);
			visited[_next] = 0;
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++) a[i][j] = s[j];
	}
	visited[(int) a[0][0] - 'A'] = 1;
	go(0, 0,1);	
	cout << ret;
	return 0;
}