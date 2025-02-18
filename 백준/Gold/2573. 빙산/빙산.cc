#include<bits/stdc++.h>
using namespace std;
int n, m, y, x, ny, nx;
int a[304][304];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<pair<int,int>> vec;
int visited[304][304];
int ret;
int com;
void go(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; int nx = x + dx[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if (visited[ny][nx]|| a[ny][nx] == 0) continue;
		go(ny, nx);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) 
				vec.push_back({ i,j });
		}


	// 이미 2개 이상일 경우 
	com = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] || a[i][j] == 0) continue;
			go(i, j); com++;
		}
	}		
	if (com >= 2) {
		cout << 0; return 0;
	}		
	fill(&visited[0][0], &visited[0][0] +304* 304, 0);

	// 0에 대해서 주변 탐색
	while (true) {
		ret++;
		vector<pair<int, int>> tem;
		com = 0;
		for (pair<int, int> p : vec) {
			y = p.first; x = p.second;
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i]; nx = x + dx[i];
				if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
				// if (visited[ny][nx]) continue;
				if (a[ny][nx] == 0) continue;
				// visited[ny][nx] = 1;
				a[ny][nx]-=1;
				if (a[ny][nx] == 0) tem.push_back({ ny,nx });
			}
		}

		// 이후에 dfs실시해서 component 찾기		
		fill(&visited[0][0], &visited[0][0] + n * m, 0);
		int _stop = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] || a[i][j] == 0) continue;
				if (a[i][j] != 0) _stop = false;
				go(i, j);  
				com++;
			}
		}
		//cout << "\nthis a\n";
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {
		//		cout << a[i][j] << " ";
		//	}cout << "\n";
		//}

		// cout << com << ", " << _stop << "<- \n";

		// 종료 조건
		if (com >= 2) {
			cout << ret;
			return 0;
		}
		if (_stop) break;
		// 다음을 위한 초기화
		fill(&visited[0][0], &visited[0][0] + 304 * 304, 0);
		for (pair<int, int> p : tem) vec.push_back(p);
		tem.clear();
	}
	// _stop의 조건
	cout << 0;
	return 0;
}