#include <bits/stdc++.h>
using namespace std;

int n, m, y, x, ny, nx, tem, result;
int a[8][8];
int visited[8][8];
int ret = 0;
vector<pair<int, int>> ones;
bool v = false;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if (a[ny][nx] == 2) {
			v = true;
		}
		if (a[ny][nx] == 0 && !visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
	tem++;
	return;
}

void go() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 && !visited[i][j]) {
				//
				tem = 0;
				dfs(i, j);
				if (!v) ret += tem;
				v = false;
			}
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) ones.push_back({ i,j });
		}
	}
	//
	for (int i = 0; i < ones.size(); i++) {
		for (int j = i + 1; j < ones.size(); j++) {
			for (int k = j + 1; k < ones.size(); k++) {
				a[ones[i].first][ones[i].second] = 1;
				a[ones[j].first][ones[j].second] = 1;
				a[ones[k].first][ones[k].second] = 1;
				go();
				result = max(result, ret);
				//
				ret = 0;
				a[ones[i].first][ones[i].second] = 0;
				a[ones[j].first][ones[j].second] = 0;
				a[ones[k].first][ones[k].second] = 0;
				fill(&visited[0][0], &visited[0][0] + 8 * 8, 0);
			}
		}
	}
	cout << result;
	return 0;
}