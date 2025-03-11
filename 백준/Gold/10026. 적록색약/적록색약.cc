#include<bits/stdc++.h>
using namespace std;
int n;
string s;
char normal[104][104];
char special[104][104];
int visited[104][104];
// DFS => connected components
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt = 0;
void go(int y, int x, int type) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; int nx = x + dx[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[ny][nx]) continue;
		if (type && special[y][x] == special[ny][nx]) go(ny, nx, type);
		else if (normal[y][x] == normal[ny][nx]) go(ny, nx, type);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			normal[i][j] = s[j];
			if (s[j] == 'R' || s[j] == 'G') special[i][j] = 'R';
			else special[i][j] = 'B';
		}
	}

	// normal
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				go(i, j, 0); cnt++;
			}
			
		}
	}
	cout << cnt << " ";
	cnt = 0; fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);

	// special
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				go(i, j, 1); cnt++;
			}

		}
	}
	cout << cnt;

	return 0;
}