#include<bits/stdc++.h>
using namespace std;
int n, l, r, ny, nx;
int a[50][50];
int visited[50][50];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<pair<int,int>> vec;
int ret = 0;
void go(int y, int x) {
	visited[y][x] = 1;
	// 넣기
	vec.push_back({ y,x });
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || nx >= n || ny >= n) continue;
		if (!visited[ny][nx] && (l <= abs(a[y][x] - a[ny][nx])) && ( abs(a[y][x] - a[ny][nx]))<=r ){
			go(ny, nx);
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	while (true) {
		bool flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					go(i, j);
				}
				int tem = 0;
				if (vec.size() != 1&&!vec.empty()) {
					// 방문한게 2개 이상이다 
					flag = true;

					for (pair<int, int> p : vec) {
						tem += a[p.first][p.second];
					}
					for (pair<int, int> p : vec) {
						a[p.first][p.second] =int( tem / vec.size());
					}

				}

				tem = 0;
				vec.clear();
			}
		}
		
		if (!flag) break;
		else {
			ret++; fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);
		}

	}
	cout << ret;

	return 0;
}