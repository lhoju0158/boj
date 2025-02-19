#include<bits/stdc++.h>
using namespace std;
int n, m, d, s;
int state[54][54];		int preC[54][54];
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
vector<pair<int, int>> clouds; // 매번 초기화 필요
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) cin >> state[i][j];
	// 공격
	// 초기 구름
	clouds.push_back({ n - 1,0 });	clouds.push_back({ n - 1,1});
	clouds.push_back({ n - 2,0 });	clouds.push_back({ n - 2,1 });
	while (m--) {
		cin >> d >> s;
		d--;
		// 구름 좌표 이동
		for (int i = 0; i < clouds.size(); i++) {
			int y = clouds[i].first; int x = clouds[i].second;
			int ny = y + (s * dy[d]); int nx = x + (s * dx[d]);
			if (ny < 0) { while (ny < 0)	ny += n; }
			else if (ny >= n) { while (ny >= n) ny -= n; }
			if (nx < 0) { while (nx < 0)nx += n; }
			else if (nx >= n) { while (nx >= n) nx -= n; }
			clouds[i] = { ny,nx };
		}
		for (pair<int, int> p : clouds) {
			int y = p.first; int x = p.second;
			state[y][x]++; // 비 양 ++
		}
		for (pair<int, int> p : clouds) {
			int y = p.first; int x = p.second;
			for (int i : {1, 3, 5, 7}) {
				int ny = y + dy[i]; int nx = x + dx[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (state[ny][nx] == 0) continue;
				state[y][x]++;
			}
			preC[y][x] = 1; // 이전 정보 저장
		}

		// 구름 clear
		clouds.clear();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (state[i][j] >= 2&&preC[i][j]!=1) {
					state[i][j] -= 2;
					clouds.push_back({ i,j });
				}
			}
		}
		fill(&preC[0][0], &preC[0][0] + 54 * 54, 0);
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ret += state[i][j];
		}
	}
	cout << ret;
	return 0;
}