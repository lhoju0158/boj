#include<bits/stdc++.h>
using namespace std;
int n, m;
string s;
int a[54][54], visited[54][54];
vector<pair<int, int>> ls;
queue<pair<int, int>> q;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1, };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
			if (a[i][j] == 'L') ls.push_back({ i,j });
		}
	}
	if (ls.empty()) {
		cout << 0;
		return 0;
	}
	int result = 0;
	for (int i = 0;i<ls.size();i++) {
		pair<int, int>p = ls[i];
		if (visited[p.first][p.second]) continue;
		visited[p.first][p.second] = 1;
		q.push(p);
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || nx >= m || ny >= n) continue;
				if (a[ny][nx] == 'W' || visited[ny][nx]) continue;
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
		int tem = 0;
		for (pair<int, int> p : ls) {
			tem = max(tem, visited[p.first][p.second]);
		}
		result = max(result, tem);
		fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
	}
	cout << result-1;
}