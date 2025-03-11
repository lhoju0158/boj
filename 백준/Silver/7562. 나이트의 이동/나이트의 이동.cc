#include<bits/stdc++.h>
using namespace std;
int n;
int l;
int nowX, nowY;
int targetX, targetY;
int visited[304][304];
int dx[8] = { -1,1,-1,1,-2,2,-2,2 };
int dy[8] = { -2,2,2,-2,-1,1,1,-1 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> l >> nowY >> nowX >> targetY >> targetX;
		fill(&visited[0][0], &visited[0][0] + 304*304, 0);
		queue<int> q;
		q.push(nowY * 1000 + nowX); visited[nowY][nowX] = 1;
		while (!q.empty()) {
			int y = q.front() / 1000; int x = q.front() % 1000; q.pop();
			if (visited[targetY][targetX]) break;
			for (int i = 0; i < 8; i++) {
				int ny = y + dy[i]; int nx = x + dx[i];
				if (nx < 0 || ny < 0 || nx >= l || ny >= l || visited[ny][nx]) continue;
				visited[ny][nx] = visited[y][x] + 1;
				q.push(ny * 1000 + nx);
			}
		}
		cout << visited[targetY][targetX] - 1 << "\n";
	}

	return 0;
}